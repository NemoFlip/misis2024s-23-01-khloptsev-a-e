#include <chrono>
#include <queuelst/queuelst.hpp>
#include <iostream>

int main() {
  std::chrono::steady_clock::time_point start_push = std::chrono::steady_clock::now();
  QueueLst queuelst1 { };
  Complex compl1 = {1.1, 1.0};
  for (int i = 0; i <= 10000; i += 1) {
    queuelst1.Push(compl1);
  }
  std::chrono::steady_clock::time_point end_push = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration<float>{end_push - start_push}.count() << " push test" << std::endl;
  auto start_pop = std::chrono::steady_clock::now();
  while (!queuelst1.IsEmpty()) {
    queuelst1.Pop();
  }
  auto end_pop = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration<float>{end_pop - start_pop}.count() << " pop test" << std::endl;

  QueueLst queueLst2 { };
  for (int i = 0; i <= 10000; i += 1) {
    queueLst2.Push(compl1);
  }
  QueueLst queueLst3 { };
  auto start_equal = std::chrono::steady_clock::now();
  queueLst3 = queueLst2;
  auto end_equal = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration<float>{end_equal - start_equal}.count() << " copy equal test" << std::endl;

  QueueLst queueLst4 { };
  auto start_move_equal = std::chrono::steady_clock::now();
  queueLst4 = std::move(queueLst2);
  auto end_move_equal = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration<float>{end_move_equal - start_move_equal}.count() << " move equal test" << std::endl;
  


}