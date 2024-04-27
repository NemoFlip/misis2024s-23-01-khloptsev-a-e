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


TEST_CASE_TEMPLATE("StackLstt push/pop methods tests", T, int, double, std::string, Complex) {
  std::vector<T> vec1 { };
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

TEST_CASE_TEMPLATE("Stacklstt operator= tests", T, int, double, std::string, Complex) {
  std::vector<T> vec1 { };
  make_vector(vec1);
  StackLstT<T> stack1;
  for (T& value : vec1) {
    stack1.Push(value);
  }
  StackLstT<T> stack2 { };
  for (T& value : vec1) {
    stack2.Push(value);
  }
  stack2.Pop();
  stack1 = stack2;
  CHECK_EQ(stack1.Top(), stack2.Top());
  while (!stack1.IsEmpty() && !stack2.IsEmpty()) {
    stack1.Pop();
    stack2.Pop();
    if (!stack1.IsEmpty() && !stack2.IsEmpty()) {
      CHECK_EQ(stack1.Top(), stack2.Top());
    }
  }
  CHECK(stack1.IsEmpty());
  CHECK(stack2.IsEmpty());
}