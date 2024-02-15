#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stacklst/stacklst.hpp>

TEST_CASE("StackLst tests") {
  StackLst stackLst1;
  Complex val1;

  stackLst1.Push(val1);
  CHECK_EQ(stackLst1.Top(), val1);

  stackLst1.Pop();
  CHECK(stackLst1.IsEmpty());
  CHECK_THROWS(stackLst1.Top());


}