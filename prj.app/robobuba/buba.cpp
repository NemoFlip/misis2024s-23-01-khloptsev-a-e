#include <iostream>
#include <vector>
#include <string>

class Command {
public:
    virtual void operation(std::vector<int>& nums, int& curr_index);
};

class Left: public Command {
public:
    Left(const int value): val { value } { }
    void operation(std::vector<int>& nums, int& curr_index) override {
      int vec_size = static_cast<int>(nums.size());
      curr_index = (vec_size + curr_index - (val % vec_size)) % vec_size;
    }
private:
    int val = 0;
};
class Right: public Command {

public:
    Right(const int value): val { value } { }
    void operation(std::vector<int>& nums, int& curr_index) override {
      int vec_size = static_cast<int>(nums.size());
      curr_index = (curr_index + (val % vec_size)) % vec_size;
    }
private:
    int val = 0;
};

class Add: public Command {
public:
    Add(const int value): val { value } { }
    void operation(std::vector<int>& nums, int& curr_index) override {
      nums[curr_index] += val;
    }
private:
    int val = 0;
};

class Sub: public Command {
public:
    Sub(const int value): val { value } { }
    void operation(std::vector<int>& nums, int& curr_index) override {
      nums[curr_index] -= val;
    }
private:
    int val = 0;
};
void Go(std::vector<int>& nums, const std::vector<Command>& commands) {
  int curr_index = 0;
  for (Command com : commands) {
    com.operation(nums, curr_index);
  }

}
int main() {
  std::string str_func;
  std::vector<Command> commands;
  int val = 0;
  while (std::cin >> str_func && std::cin >> val) {
    if (str_func == "LEFT") {
      commands.push_back(Left(val));
    } else if (str_func == "RIGHT") {
      commands.push_back(Right(val));
    } else if (str_func == "ADD") {
      commands.push_back(Add(val));
    } else if (str_func == "SUB") {
      commands.push_back(Sub(val));
    } else if (str_func == "GO" && !commands.empty()) {
      std::vector<int> nums(val, 0);
      Go(nums, commands); // invoke go function which runs all commands
    } else if (str_func == "REV") {
      //TODO: make "REV" func
    }

  }
  return 0;

}