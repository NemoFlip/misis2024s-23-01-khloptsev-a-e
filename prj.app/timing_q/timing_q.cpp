#include <chrono>
#include <queuelst/queuelst.hpp>
#include <iostream>

int main() {
  std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  QueueLst queuelst1 { };
  Complex compl1 = {1.1, 1.0};
  queuelst1.Push(compl1);
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration<float>{end - start}.count();

}