#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <stacklstt/stacklstt.hpp>
#include "doctest.h"

TEST_CASE("some tests") {
  StackLstT<int> stacklst1 { };
  stacklst1.Push(5);
  CHECK_EQ(stacklst1.Top(), 5);

}