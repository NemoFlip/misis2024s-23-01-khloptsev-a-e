#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuearr/queuearr.hpp>

TEST_CASE("tests") {
  QueueArr queue1 { };
  Complex compl1 = {1.0, 0.0};
  Complex compl2 = {2.0, 0.0};
  queue1.Push(compl1);
  queue1.Push(compl2);
  CHECK_EQ(queue1.Top(), compl1);
  queue1.Pop();
  CHECK_EQ(queue1.Top(), compl2);
  queue1.Pop();
  CHECK_THROWS(queue1.Top());
  CHECK(queue1.IsEmpty());
}