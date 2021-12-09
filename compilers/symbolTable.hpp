#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

enum Type { INTEGER = 1, SIN_TIPO = 2 };

class Element {
public:
  Type type;
  string name;
  virtual ~Element() {}
};

class Variable : public Element {
public:
  Variable(Type type, string name) {
    if (type == Type::SIN_TIPO) {
      cerr << "Error: variable " << name << " no tiene tipo" << endl;
      exit(1);
    }
    this->type = type;
    this->name = name;
  }
};

class VariableArray : public Element {
public:
  size_t size;

  VariableArray(Type type, string name, size_t size) {
    if (type == Type::SIN_TIPO) {
      cerr << "Error: variable " << name << " no tiene tipo" << endl;
      exit(1);
    }
    this->type = type;
    this->name = name;
    this->size = size;
  }
};

class Function : public Element {
public:
  vector<Variable *> params;

  Function(Type type, string name, vector<Variable *> params) {
    this->type = type;
    this->name = name;
    this->params = params;
  }
};

// singleton Structure class
// scope = '0-FUNCTIONNAME'
// scope = '1-' : if, while, variable

class Structure {
private:
  static Structure *instance;

  unordered_map<string, vector<Element *>> elements;

  Structure() : elements() {}

public:
  Structure(Structure const &) = delete;
  void operator=(Structure const &) = delete;

  static Structure *GetInstance();

  void addElement(string scope, Element *element) {
    elements[scope].push_back(element);
  }

  int getSize(string scope) { return elements[scope].size(); }
};

Structure *Structure::instance = nullptr;

Structure *Structure::GetInstance() {
  if (instance == nullptr) {
    instance = new Structure();
  }
  return instance;
}
