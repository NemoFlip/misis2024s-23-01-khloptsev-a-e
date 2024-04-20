#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklst/stacklst.hpp>

TEST_CASE("StackLst methods tests") {
  StackLst stackLst1;
  Complex val1;
  // Push test
  stackLst1.Push(val1);
  CHECK_EQ(stackLst1.Top(), val1);
  // Pop test
  stackLst1.Pop();
  CHECK(stackLst1.IsEmpty());
  CHECK_THROWS(stackLst1.Top());
  stackLst1.Pop();

}

TEST_CASE("stacklst ctor") {
  // Testing with 3 elements
  StackLst stack1;
  Complex compl1 {1.1, 2.3};
  Complex compl2 {1.2, 2.3};
  Complex compl3 {1.3, 2.3};
  stack1.Push(compl1);
  stack1.Push(compl2);
  stack1.Push(compl3);

  StackLst stack2 {stack1};
  CHECK_EQ(stack2.Top(), compl3);
  stack2.Pop();
  CHECK_EQ(stack2.Top(), compl2);
  stack2.Pop();
  CHECK_EQ(stack2.Top(), compl1);
  stack2.Pop();
  CHECK(stack2.IsEmpty());

  // Testing with empty stack
  StackLst emptyStack = StackLst();
  StackLst from_empty_stack {emptyStack};
  CHECK(from_empty_stack.IsEmpty());

  // Testing with 1 element
  StackLst one_elem_stack = StackLst();
  Complex val1 = Complex(5.0, 2.0);
  one_elem_stack.Push(val1);
  StackLst from_one_stack {one_elem_stack};
  CHECK_EQ(from_one_stack.Top(), val1);
  from_one_stack.Pop();
  CHECK(from_one_stack.IsEmpty());
}
TEST_CASE("Operator of equality tests") {
  // Testing with 3 elements
  StackLst stack1;
  Complex compl1{1.1, 2.3};
  Complex compl2{1.2, 2.3};
  Complex compl3{1.3, 2.3};
  stack1.Push(compl1);
  stack1.Push(compl2);
  stack1.Push(compl3);

  StackLst stack2 = stack1;
  CHECK_EQ(stack2.Top(), compl3);
  stack2.Pop();
  CHECK_EQ(stack2.Top(), compl2);
  stack2.Pop();
  CHECK_EQ(stack2.Top(), compl1);
  stack2.Pop();
  CHECK(stack2.IsEmpty());
}

TEST_CASE("Clear method test") {
  StackLst stack1;
  Complex compl1{1.1, 2.3};
  Complex compl2{1.2, 2.3};
  Complex compl3{1.3, 2.3};
  stack1.Push(compl1);
  stack1.Push(compl2);
  stack1.Push(compl3);
  stack1.Clear();
  CHECK(stack1.IsEmpty());
  CHECK_THROWS(stack1.Top());
}

TEST_CASE("operator=: lhs has elements") {
  StackLst stack1 { };
  Complex compl1{1.1, 2.3};
  Complex compl2{1.2, 2.3};
  Complex compl3{1.3, 2.3};
  stack1.Push(compl1);
  stack1.Push(compl2);
  stack1.Push(compl3);

  StackLst stack2 { };
  Complex compl4{1.4, 2.3};
  Complex compl5{1.5, 2.3};
  Complex compl6{1.6, 2.3};
  stack2.Push(compl4);
  stack2.Push(compl5);
  stack2.Push(compl6);

  // Check when lhs and rhs has 3 elements
  stack1 = stack2;
  CHECK_EQ(stack1.Top(), compl6);
  // Check when lhs has 3 elements, rhs has 4 elements
  Complex compl7 {1.5, 2.3};
  stack2.Push(compl7);
  stack1 = stack2;
  CHECK_EQ(stack1.Top(), compl7);
  // Check when lhs has 0 elements, rhs has 4 elements
  stack1.Clear();
  stack1 = stack2;
  CHECK_EQ(stack1.Top(), compl7);
  // Check when lhs has 4 elements, rhs has 3 elements
  stack2.Pop();
  stack1 = stack2;
  CHECK_EQ(stack1.Top(), compl6);
  stack1.Pop();
  CHECK_EQ(stack1.Top(), compl5);
  stack1.Pop();
  CHECK_EQ(stack1.Top(), compl4);
  stack1.Pop();
  CHECK(stack1.IsEmpty());
}
