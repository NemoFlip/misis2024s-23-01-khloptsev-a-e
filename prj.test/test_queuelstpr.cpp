#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("QueueLstPr push and pop tests") {
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

TEST_CASE("QueueLstPr ctor tests") {
  QueueLstPr queuepr1;
  float elem1 = 1.0;
  float elem2 = 2.0;
  float elem3 = 1.5;
  queuepr1.Push(elem1);
  queuepr1.Push(elem2);
  queuepr1.Push(elem3);
  QueueLstPr queuepr2 { queuepr1 };
  CHECK_EQ(queuepr2.Top(), elem1);
  queuepr2.Pop();
  CHECK_EQ(queuepr2.Top(), elem3);
  queuepr2.Pop();
  CHECK_EQ(queuepr2.Top(), elem2);
  queuepr2.Pop();
  CHECK(queuepr2.IsEmpty());
}

TEST_CASE("QueueLstPr 'operator=' tests") {
  QueueLstPr queuepr1;
  float elem1 = 1.0;
  float elem2 = 2.0;
  float elem3 = 1.5;
  queuepr1.Push(elem1);
  queuepr1.Push(elem2);
  queuepr1.Push(elem3);
  QueueLstPr queuepr2 = queuepr1;
  CHECK_EQ(queuepr2.Top(), elem1);
  queuepr2.Pop();
  CHECK_EQ(queuepr2.Top(), elem3);
  queuepr2.Pop();
  CHECK_EQ(queuepr2.Top(), elem2);
  queuepr2.Pop();
  CHECK(queuepr2.IsEmpty());
}