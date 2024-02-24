#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelst/queuelst.hpp>

TEST_CASE("push and pop methods test") {
  QueueLst queue1 = { };
  Complex compl1 = Complex{1.1, 3.2};
  Complex compl2 = Complex{1.2, 3.3};
  queue1.Push(compl1);
  queue1.Push(compl2);
  queue1.Pop();
  CHECK(!queue1.IsEmpty());
  queue1.Pop();
  CHECK(queue1.IsEmpty());
  CHECK_NOTHROW(queue1.Pop());
}

TEST_CASE("ctor tests") {
  QueueLst queue1 = QueueLst();
  QueueLst queue2 = { queue1 };
  CHECK(queue2.IsEmpty());

  Complex compl1 = {1.1, 2.1};
  queue1.Push(compl1);
  QueueLst queue3 { queue1 };
  CHECK_EQ(queue3.Top(), compl1);

  Complex compl2 = { 1.2, 2.2};
  queue1.Push(compl2);
  QueueLst queue4 { queue1 };
  CHECK_EQ(queue4.Top(), compl1);
  queue4.Pop();
  CHECK_EQ(queue4.Top(), compl2);
}

TEST_CASE("operator= tests") {
  QueueLst queue1 = { };
  Complex compl1 = {1.1, 2.1};
  Complex compl2 = {1.2, 2.2};
  Complex compl3 = {1.3, 2.3};
  queue1.Push(compl1);
  queue1.Push(compl2);
  queue1.Push(compl3);
  QueueLst queue2 = { };
  queue2 = queue1;
  CHECK_EQ(queue2.Top(), compl1);
  queue2.Pop();
  CHECK_EQ(queue2.Top(), compl2);
  queue2.Pop();
  CHECK_EQ(queue2.Top(), compl3);
  queue2.Pop();
  CHECK(queue2.IsEmpty());
}

