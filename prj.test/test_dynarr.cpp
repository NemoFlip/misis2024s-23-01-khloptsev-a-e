#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <dynarr/dynarr.hpp>

TEST_CASE("dynarr ctor") {
  DynArr arr_def;
  CHECK_EQ(arr_def.Size(), 0);

  DynArr arr_s = DynArr(10);
  CHECK_EQ(arr_s.Size(), 10);
  CHECK_EQ(arr_s[0], 0);
  CHECK_EQ(arr_s[arr_s.Size() - 1], 0);
  CHECK_THROWS(DynArr(-5));

  DynArr arr_from_s = DynArr(arr_s);
  CHECK_EQ(arr_from_s.Size(), 10);
}

TEST_CASE("assignment and memory access operators") {
  DynArr arr1 = DynArr(10);
  DynArr arr2 = arr1;
  CHECK_EQ(arr2.Size(), 10);

  arr1[1] = 10;
  CHECK_EQ(arr1[1], 10);
  CHECK_THROWS(void(arr1[-1]));
  CHECK_THROWS(void(arr1[10]));
}

TEST_CASE("methods tests") {
  DynArr arr_test = DynArr(10);
  CHECK_EQ(arr_test.Size(), 10);


  // Tests with Resize method: Part 1
  arr_test.Resize(11);
  CHECK_EQ(arr_test.Size(), 11);

  arr_test.Resize(10);
  CHECK_EQ(arr_test.Size(), 10);

  CHECK_THROWS(arr_test.Resize(-5));
  // Tests with Resize method: Part 2

  DynArr arr_r = DynArr(10);
  for (std::ptrdiff_t i = 0; i < arr_r.Size(); i += 1) {
    arr_r[i] = 5;
  }

  arr_r.Resize(12);
  CHECK_EQ(arr_r[0], 5);
  CHECK_EQ(arr_r[9], 5);
  CHECK_EQ(arr_r[10], 0);
  CHECK_EQ(arr_r[11], 0);
  CHECK_EQ(arr_r[arr_r.Size() - 1], 0);
}

