#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <bitset/bitset.hpp>

TEST_CASE("some tests") {
  BitSet bitset1 = BitSet(31);
  bitset1.Set(0, true);
  CHECK_EQ(bitset1.Get(0), true);
  bitset1.Set(0, false);
  CHECK_EQ(bitset1.Get(0), false);

  bitset1.Resize(32);
  bitset1.Set(31, true);
  CHECK_EQ(bitset1.Get(31), true);

  BitSet bitset2 = BitSet(14);

  CHECK_THROWS(bitset1 & bitset2);



}