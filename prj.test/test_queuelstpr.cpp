#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("QueueLstPr tests") {
  QueueLstPr queuepr1;
  float elem1 = 1.0;
  float elem2 = 2.0;
  float elem3 = 1.5;
  queuepr1.Push(elem1);
  queuepr1.Push(elem2);
  queuepr1.Push(elem3);
  CHECK_EQ(queuepr1.Top(), elem1);
  queuepr1.Pop();
  CHECK_EQ(queuepr1.Top(), elem3);
  queuepr1.Pop();
  CHECK_EQ(queuepr1.Top(), elem2);
  queuepr1.Pop();
  CHECK(queuepr1.IsEmpty());




}