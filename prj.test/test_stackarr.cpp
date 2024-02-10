#include <iostream>
#include <stackarr/stackarr.hpp>

int main() {
  StackArr stack1 = StackArr();
  stack1.Push(Complex(1.5, 2));
  std::cout << stack1.IsEmpty() << std::endl;
//  std::cout << stack1.Top() << std::endl;
  std::cout << stack1.GetTopIndex() << std::endl;
  stack1.Pop();
  std::cout << stack1.GetTopIndex() << std::endl;
  stack1.Pop();
  std::cout << stack1.GetTopIndex() << std::endl;




}