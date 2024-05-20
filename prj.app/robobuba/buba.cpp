#include <iostream>
#include <vector>

class Command {
public:
    virtual void operation(std::vector<int>& nums, const int val, int& curr_index);
};

class Left: public Command {
public:
    void operation(std::vector<int>& nums, const int val, int& curr_index) override {
      int vec_size = static_cast<int>(nums.size());
      curr_index = (vec_size + curr_index - (val % vec_size)) % vec_size;
    }
};
class Right: public Command {
public:
    void operation(std::vector<int>& nums, const int val, int& curr_index) override {
      int vec_size = static_cast<int>(nums.size());
      curr_index = (curr_index + (val % vec_size)) % vec_size;
    }
};

class Add: public Command {
public:
    void operation(std::vector<int>& nums, const int val, int& curr_index) override {
      nums[curr_index] += val;
    }
};

class Sub: public Command {
public:
    void operation(std::vector<int>& nums, const int val, int& curr_index) override {
      nums[curr_index] -= val;
    }
};

int main() {
  std::vector<int> numbers { };


}