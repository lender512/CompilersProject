#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum Type { INTEGER = 1, SIN_TIPO = 2 };

struct Element {
  Type type;
  //string name;
  virtual ~Element() {}
};

struct Variable : public Element {
  Variable(Type type) {
    if (type == Type::SIN_TIPO) {
      cerr << "Error: variable " << "as" << " no tiene tipo" << endl;
      exit(1);
    }
    this->type = type;
  }
};

struct VariableArray : public Element {
  size_t size;

  VariableArray(Type type, size_t size) {
    if (type == Type::SIN_TIPO) {
      cerr << "Error: variable " << "as" << " no tiene tipo" << endl;
      exit(1);
    }
    this->type = type;
    this->size = size;
  }
};

struct Function : public Element {
  vector<Variable *> params;

  Function(Type type, vector<Variable *> params) {
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

  unordered_map<string, Element*> elements;

  Structure() : elements() {}

  void checkIfExists(string name) {
    if (elements.find(name) != elements.end()) {
      cerr << "Error: variable " << name << " ya existe" << endl;
      exit(1);
    }
  }

public:
  Structure(Structure const &) = delete;
  void operator=(Structure const &) = delete;

  static Structure *getInstance();

  void addVariable(string name, int type) {
    checkIfExists(name);
    Variable* variable = new Variable((Type) type);

    elements[name] = variable;
  }

  void addVariableArray(string name, int type, size_t size) {
    checkIfExists(name);
    VariableArray* variable = new VariableArray((Type) type, size);
    elements[name] = variable;
  }

  int countVariables() {
    return elements.size();
  }

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
      if (dynamic_cast<Variable*>(it->second)) {
        cout << "INTEGER" << endl;
      } else if (dynamic_cast<VariableArray*>(it->second)) {
        cout << "ARRAY" << endl;
      }
    }
  }
};

Structure *Structure::instance = nullptr;

Structure *Structure::getInstance() {
  if (instance == nullptr) {
    instance = new Structure();
  }
  return instance;
}
