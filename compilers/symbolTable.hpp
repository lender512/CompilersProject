#include <any>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum Type { INTEGER = 1, SIN_TIPO = 2 };

string typeToString(Type type) {
  switch (type) {
  case INTEGER:
    return "INTEGER";
  case SIN_TIPO:
    return "SIN_TIPO";
  default:
    return "";
  }
}

struct Element {
  Type type;
  int scope;
  // string name;
  virtual ~Element() {}
};

struct Variable : public Element {
  Variable(Type type, int scope) {
    this->type = type;
    this->scope = scope;
  }
};

struct VariableArray : public Element {
  size_t size;

  VariableArray(Type type, size_t size, int scope) {
    this->type = type;
    this->size = size;
    this->scope = scope;
  }
};

struct Function : public Element {
  vector<Element *> params;
  int paramNumber;

  Function(Type type, int paramNumber, int scopeId) {
    this->type = type;
    this->paramNumber = paramNumber;
    this->scope = scopeId;
  }

  void setParams(vector<Element *> params) { this->params = params; }
};

// each element will have its scope
// the default scope (init) is -1
// scope will increment acording to the order of each function
class Structure {
private:
  static Structure *instance;

  unordered_map<string, Element *> elements;

  Structure() : elements() {}

  void checkIfExists(string name, int scopeId) {
    if (elements.find(name) != elements.end()) {
      cout << elements[name]->scope << endl;
      cout << scopeId << endl;
    }
    if (elements.find(name) != elements.end() && elements[name]->scope == 0) {
      cerr << "Error: variable " << name << " already exists" << endl;
      throw std::runtime_error("failure");
    }

    if (elements.find(name) != elements.end() &&
        elements[name]->scope == scopeId) {
      cerr << "Error: variable " << name << " already exists" << endl;
      throw std::runtime_error("failure");
    }
  }

  void checkIfAccesible(string name, string type, bool condition = false) {
    if (elements.find(name) == elements.end() && condition == true) {
      cerr << "Error: " << type << " " << name << " has not been declared"
           << endl;
      throw std::runtime_error("failure");
    }

    if (elements.find(name) == elements.end()) {
      if (name.find_last_of('_') == string::npos) {
        cerr << "Error: " << type << " " << name << " has not been declared"
             << endl;
        throw std::runtime_error("failure");
      }

      string baseName = name.substr(0, name.find_last_of('_'));
      checkIfAccesible(baseName + "_0", type, true);
    }
  }

public:
  Structure(Structure const &) = delete;
  void operator=(Structure const &) = delete;

  static Structure *getInstance();

  void addVariable(string name, int type, int scopeId) {
    checkIfExists(name, scopeId);
    Variable *variable = new Variable((Type)type, scopeId);

    elements[name] = variable;
  }

  void addVariableArray(string name, int type, size_t size, int scopeId) {
    checkIfExists(name, scopeId);
    VariableArray *variable = new VariableArray((Type)type, size, scopeId);
    elements[name] = variable;
  }

  // varadic tamplate of string name, int type
  void addFunction(string name, int type, int paramNumber, int scopeId) {
    checkIfExists(name, scopeId);
    Element *function = new Function((Type)type, paramNumber, scopeId);
    elements[name] = function;
  }

  // variable y variableArray
  void searchVariable(string name, int scopeId) {
    checkIfAccesible(name, "variable");
    if (dynamic_cast<Function *>(elements[name])) {
      cerr << "Error: can not assign function " << name << endl;
      throw std::runtime_error("failure");
    }
  }

  void searchVariableFunction(string name, int type,
                              vector<tuple<string, int>> params, int scopeId) {
    checkIfAccesible(name, "function");
    if (dynamic_cast<Variable *>(elements[name]) ||
        dynamic_cast<VariableArray *>(elements[name])) {
      cerr << "Error: can not assign variable or variableArray " << name
           << endl;
      throw std::runtime_error("failure");
    }

    if (dynamic_cast<Function *>(elements[name])->type != type) {
      cerr << "Error: function " << name << " was previously declared as "
           << typeToString(elements[name]->type) << endl;
      throw std::runtime_error("failure");
    }

    if (dynamic_cast<Function *>(elements[name])->paramNumber !=
        params.size()) {
      cerr << "Error: function " << name << " was previously declared with "
           << dynamic_cast<Function *>(elements[name])->paramNumber
           << " parameter(s)" << endl;
      throw std::runtime_error("failure");
    }

    vector<Element *> variables;
    for (std::tuple<string, int> &i : params) {
      string name_ = std::get<0>(i);
      int type_ = std::get<1>(i);

      checkIfExists(name_ + "_" + std::to_string(scopeId), scopeId);

      Element *variable = new Variable((Type)type_, scopeId);
      elements[name_ + "_" + std::to_string(scopeId)] = variable;
      variables.push_back(variable);
    }

    dynamic_cast<Function *>(elements[name])->setParams(variables);
  }

  void searchFunctionUse(string name, int currentParamNumberInUse) {
    checkIfAccesible(name, "function");

    if (dynamic_cast<Variable *>(elements[name]) ||
        dynamic_cast<VariableArray *>(elements[name])) {
      cerr << "Error: " << name << " Variable-VariableArray is not callable"
           << endl;
      throw std::runtime_error("failure");
    }
    if (dynamic_cast<Function *>(elements[name])->params.size() !=
        currentParamNumberInUse) {
      cerr << "Error: function " << name << " was called with "
           << currentParamNumberInUse << " arguments "
           << "when it was declared with "
           << dynamic_cast<Function *>(elements[name])->params.size() << endl;
      throw std::runtime_error("failure");
    }
  }

  // add function with varadic template of vector<name, type>

  int countVariables() { return elements.size(); }

  void printNice() {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
      cout << it->first << " ";
      if (it->second->type == Type::INTEGER) {
        cout << "INTEGER" << endl;
      } else if (it->second->type == Type::SIN_TIPO) {
        cout << "SIN_TIPO" << endl;
      }
    }
  }

  void printNiceType() {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
      cout << it->first << " ";
      if (dynamic_cast<Variable *>(it->second)) {
        cout << "INTEGER scope: " << it->second->scope << endl;
      } else if (dynamic_cast<VariableArray *>(it->second)) {
        cout << "ARRAY scope: " << it->second->scope << endl;
      } else if (dynamic_cast<Function *>(it->second)) {
        cout << "FUNCTION scope: " << it->second->scope << " "
             << typeToString(it->second->type) << " ->"
             << "  ";
        cout << "PARAMS: ";
        for (Element *e : dynamic_cast<Function *>(it->second)->params) {
          cout << typeToString(e->type) << " ";
        }
        cout << endl;
      }
    }
  }

  ~Structure() {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
      delete it->second;
    }
    elements.clear();
  }

  void resetSingleton() { instance = nullptr; }
};

Structure *Structure::instance = nullptr;

Structure *Structure::getInstance() {
  if (instance == nullptr) {
    instance = new Structure();
    instance->addFunction("main", 1, 0, 0);
    instance->addFunction("print", 2, 0, 0);
    instance->addFunction("input", 2, 0, 0);
  }
  return instance;
}
