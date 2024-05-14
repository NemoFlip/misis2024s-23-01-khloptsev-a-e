#include <iostream>
#include <vector>

class Command {
public:


protected:
    int curr_index { 0 };
    virtual void operation(const int val, std::vector<int>* nums);
};

class Left: private Command {


    void operation(const int val, std::vector<int>* nums) override {

    }

};

int main() {
  std::vector<int> numbers { };


}