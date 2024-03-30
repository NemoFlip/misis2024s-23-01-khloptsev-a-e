#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <bitset/bitset.hpp>

TEST_CASE("some tests") {
  BitSet bitset1 = BitSet(100);
  CHECK_EQ(bitset1.Size(), 100);
//  CHECK_EQ(bitset1.Vec().size(), 4);
  bitset1.Set(5, true);
  CHECK_EQ(bitset1.Get(5), true);

  bitset1[5] = false;
  CHECK_EQ(bitset1.Get(5), false);
  bitset1[5] = true;
  CHECK_EQ(bitset1.Get(5), true);


}