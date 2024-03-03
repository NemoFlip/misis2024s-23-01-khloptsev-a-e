#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuearr/queuearr.hpp>

TEST_CASE("test Push and Pop methods: just functionality") {
  QueueArr queue1 { };
  CHECK(queue1.IsEmpty());
  Complex compl1 = {1.0, 0.0};
  Complex compl2 = {2.0, 0.0};
  Complex compl3 = {3.0, 0.0};
  queue1.Push(compl1);
  queue1.Push(compl2);
  queue1.Push(compl3);
  CHECK_EQ(queue1.Top(), compl1);
  queue1.Pop();
  CHECK_EQ(queue1.Top(), compl2);
  queue1.Pop();
  CHECK_EQ(queue1.Top(), compl3);
  queue1.Pop();
  CHECK(queue1.IsEmpty());
}

TEST_CASE("test Push and Pop methods: make queue straight(head_ < tail_)") {
  QueueArr queue1 { };
  Complex compl1 = {1.0, 0.0};
  Complex compl2 = {2.0, 0.0};
  Complex compl3 = {3.0, 0.0};
  queue1.Push(compl1);
  queue1.Push(compl2);
  queue1.Pop();
  queue1.Push(compl3);
  CHECK_EQ(queue1.Top(), compl2);
  queue1.Pop();
  CHECK_EQ(queue1.Top(), compl3);
}

TEST_CASE("test allocation memory when queue is full") {
  QueueArr queue1 { };
  Complex compl1 = {1.0, 0.0};
  Complex compl2 = {2.0, 0.0};
  Complex compl3 = {3.0, 0.0};
  Complex compl4 = {3.0, 0.0};
  queue1.Push(compl1);
  queue1.Push(compl2);
  queue1.Pop();
  queue1.Push(compl3); // [3.0 - tail_, 2.0 - head_]
  queue1.Push(compl4);

  CHECK_EQ(queue1.Top(), compl2); // [2.0 - head_, 3.0, 4.0 - tail_]
  queue1.Pop();
  queue1.Pop();
  CHECK_EQ(queue1.Top(), compl4); // [4.0 - head_ and tail_]
  queue1.Pop();
  CHECK(queue1.IsEmpty());

}