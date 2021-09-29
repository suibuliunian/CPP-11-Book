#include "Visitor.hpp"

void TestVisitor() {
  ConcreteVisitor v;

  std::unique_ptr<Element> element1(new ConcreteElement1());
  std::unique_ptr<Element> element2(new ConcreteElement2());

  element1->Accept(v);
  element2->Accept(v);
}

int main() {
  TestVisitor();

  return 0;
}