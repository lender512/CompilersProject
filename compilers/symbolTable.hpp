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
  // string name;
  virtual ~Element() {}
};

struct Variable : public Element {
  Variable(Type type) {
    if (type == Type::SIN_TIPO) {
      cerr << "Error: variable "
           << "as"
           << " no tiene tipo" << endl;
      exit(1);
    }
    this->type = type;
  }
};

struct VariableArray : public Element {
  size_t size;

  VariableArray(Type type, size_t size) {
    if (type == Type::SIN_TIPO) {
      cerr << "Error: variable "
           << "as"
           << " no tiene tipo" << endl;
      exit(1);
    }
    this->type = type;
    this->size = size;
  }
};

struct Function : public Element {
  vector<Element *> params;

  Function(Type type, vector<Element *> params) {
    this->type = type;
    this->params = params;
  }
};

// singleton Structure class
// scope = '0-FUNCTIONNAME'
// scope = '1-' : if, while, variable

class Structure {
private:
  static Structure *instance;

  unordered_map<string, Element *> elements;

  Structure() : elements() {}

  void checkIfExists(string name) {
    if (elements.find(name) != elements.end()) {
      cerr << "Error: variable " << name << " already exists" << endl;
      exit(1);
    }
  }

public:
  Structure(Structure const &) = delete;
  void operator=(Structure const &) = delete;

  static Structure *getInstance();

  void addVariable(string name, int type) {
    checkIfExists(name);
    Variable *variable = new Variable((Type)type);

    elements[name] = variable;
  }

  void addVariableArray(string name, int type, size_t size) {
    checkIfExists(name);
    VariableArray *variable = new VariableArray((Type)type, size);
    elements[name] = variable;
  }

  // varadic tamplate of string name, int type
  void addFunction(string name, int type, vector<tuple<string, int>> params) {
    checkIfExists(name);
    vector<Element *> paramsFinal;

    for (std::tuple<string, int> &i : params) {
      string name_ = std::get<0>(i);
      int type_ = std::get<1>(i);

      checkIfExists(name_);

      Variable *variable = new Variable((Type)type_);
      elements[name_] = variable;
      paramsFinal.push_back(variable);
    }

    Element *function = new Function((Type)type, paramsFinal);
    elements[name] = function;
  }

  // variable y variableArray
  void searchVariable(string name){
    if (elements.find(name) == elements.end()) {
      cerr << "Error: variable " << name << " has not been declared" << endl;
      exit(1);
    }
    if (dynamic_cast<Function*> (elements[name])){
      cerr << "Error: can not assign function " << name  << endl;
      exit(1);
    }
  }

  void searchVariableFunction(string name, int type, int paramNumber){
    if (elements.find(name) == elements.end()) {
      cerr << "Error: function " << name << " has not been declared" << endl;
      exit(1);
    }
    if (dynamic_cast<Variable*> (elements[name]) || dynamic_cast<VariableArray*> (elements[name])){
      cerr << "Error: can not assign variable or variableArray " << name  << endl;
      exit(1);
    }

    if (dynamic_cast<Function*> (elements[name])->type != type){
      cerr << "Error: function " << name << " was previously declared as " << typeToString(elements[name]->type) << endl;
      exit(1);
    }

    if (dynamic_cast<Function*> (elements[name])->params.size() != paramNumber){
      cerr << "Error: function " << name << " was previously declared with " << dynamic_cast<Function*> (elements[name])->params.size() << " parameter(s)" << endl;
      exit(1);
    }
  }

  void searchFunctionUse(string name, int currentParamNumberInUse) {
    if (elements.find(name) == elements.end()) {
      cerr << "Error: function " << name << " has not been declared" << endl;
      exit(1);
    }
    if (dynamic_cast<Variable*> (elements[name]) || dynamic_cast<VariableArray*> (elements[name])){
      cerr << "Error: " << name << " Variable-VariableArray is not callable" << endl;
      exit(1);
    }
    if (dynamic_cast<Function*> (elements[name])->params.size() != currentParamNumberInUse){
      cerr << "Error: function " << name << " was called with " << currentParamNumberInUse << " arguments " << "when it was declared with " << dynamic_cast<Function*> (elements[name])->params.size() << endl;
      exit(1);
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
        cout << "INTEGER" << endl;
      } else if (dynamic_cast<VariableArray *>(it->second)) {
        cout << "ARRAY" << endl;
      } else if (dynamic_cast<Function *>(it->second)) {
        cout << "FUNCTION " << typeToString(it->second->type) << " ->"
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
};

Structure *Structure::instance = nullptr;

Structure *Structure::getInstance() {
  if (instance == nullptr) {
    instance = new Structure();
  }
  return instance;
}
