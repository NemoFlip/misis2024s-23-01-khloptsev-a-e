#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <stacklstt/stacklstt.hpp>
#include <complex/complex.hpp>
#include "doctest.h"
#include <string>
#include <vector>
#include <sstream>


template <typename T>
void make_vector(std::vector<T>& vec) {
  for (int val = 0; val <= 5; val += 1) {
    vec.push_back(val);
  }
}
template<>
void make_vector(std::vector<std::string>& vec) {
  for (int val = 0; val <= 5; val += 1) {
    std::stringstream ss;
    ss << val;
    std::string out_val;
    ss >> out_val;
    vec.push_back(out_val);
  }
}


TEST_CASE_TEMPLATE("StackLstt methods tests", T, int, double, std::string, Complex) {
  std::vector<T> vec1;
  make_vector(vec1);

  StackLstT<T> stack1;
  for (T& value : vec1) {
    stack1.Push(value);
  }
  int index = 5;
  while (!stack1.IsEmpty()) {
    CHECK_EQ(stack1.Top(), vec1[index]);
    stack1.Pop();
    --index;
  }
  CHECK(stack1.IsEmpty());
}