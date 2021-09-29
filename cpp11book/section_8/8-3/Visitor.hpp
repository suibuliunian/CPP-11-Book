#include <iostream>
#include <memory>

struct ConcreteElement1;
struct ConcreteElement2;

struct Visitor {
  virtual ~Visitor() {}

  virtual void Visit(ConcreteElement1* element) = 0;
  virtual void Visit(ConcreteElement2* element) = 0;
};

struct Element {
  virtual ~Element() {}

  virtual void Accept(Visitor& visitor) = 0;
};

struct ConcreteVisitor : public Visitor {
  void Visit(ConcreteElement1* element) {
    std::cout << "Visit ConcreteElement1" << std::endl;
  }

  void Visit(ConcreteElement2* element) {
    std::cout << "Visit ConcreteElement2" << std::endl;
  }
};

struct ConcreteElement1 : public Element {
  void Accept(Visitor& visitor) {
    visitor.Visit(this);
  }
};

struct ConcreteElement2 : public Element {
  void Accept(Visitor& visitor) {
    visitor.Visit(this);
  }
};

