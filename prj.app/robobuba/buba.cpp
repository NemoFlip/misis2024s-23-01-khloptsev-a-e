#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <sstream>

class Command {
public:
    virtual std::unique_ptr<Command> Create(const std::string& s) { }
protected:
    int val = 0;
};


class StoredCommand: public Command {
public:
    virtual void Operation(std::vector<int>& nums, int& curr_index) { } // curr_index - текущий индекс в массиве чисел
};

class ExecutableCommand: public Command {
public:
    virtual void DoCommand(std::vector<int>& nums, std::vector<std::unique_ptr<StoredCommand>>& commands) { }
};

class Left: public StoredCommand {
public:
    Left() = default;
    Left(const int value) {
      val = value;
    }
    void Operation(std::vector<int>& nums, int& curr_index) override {
      int vec_size = static_cast<int>(nums.size());
      curr_index = (vec_size + curr_index - (val % vec_size)) % vec_size;
    }
    std::unique_ptr<Command> Create(const std::string& s) override {
      std::stringstream sstream;
      sstream << s;
      std::string cmd;
      sstream >> cmd; // в cmd записали строку команды
      sstream >> val; // в value записали значение, идущее вместе с командой
      if (cmd == "LEFT") {
        return std::make_unique<StoredCommand>(Left(val));
      }
      return nullptr;
    }
};
class Right: public StoredCommand {
public:
    Right() = default;
    Right(const int value) {
      val = value; // почему не работает список инициализации?
    }
    void Operation(std::vector<int>& nums, int& curr_index) override {
      int vec_size = static_cast<int>(nums.size());
      curr_index = (curr_index + (val % vec_size)) % vec_size;
    }
};

class Add: public StoredCommand {
public:
    Add() = default;
    Add(const int value) {
      val = value;
    }
    void Operation(std::vector<int>& nums, int& curr_index) override {
      nums[curr_index] += val;
    }
};

class Sub: public StoredCommand {
public:
    Sub() = default;
    Sub(const int value) {
      val = value;
    }
    void Operation(std::vector<int>& nums, int& curr_index) override {
      nums[curr_index] -= val;
    }

};
class Go: public ExecutableCommand {
public:
    Go() = default;
    void DoCommand(std::vector<int>& nums, std::vector<std::unique_ptr<StoredCommand>>& commands) override {
      int curr_index = 0;
      for (const std::unique_ptr<StoredCommand>& com : commands) {
        com->Operation(nums, curr_index);
      }
      for (int v : nums) {
        std::cout << v << " ";
      }
    }
};

class Rev: public ExecutableCommand {
public:
    Rev() = default;
    void DoCommand(std::vector<int>& nums, std::vector<std::unique_ptr<StoredCommand>>& commands) override {
      if (val > commands.size()) {
        throw std::logic_error("Size of commands vector is less than value.");
      }
      for (int i = 0; i < val; i += 1) {
        commands.pop_back();
      }
    }
};


struct DataManager {
    DataManager(std::vector<std::unique_ptr<Command>> commands) {
      for (const auto& com : commands) {
       
      }
    }
    std::vector<std::unique_ptr<Command>> knownCommands; // Нельзя проиницилизировать, потому что у вектора вызывается конструктор копирования
                                                        // и он копирует все эти поинтеры

};
int main() {
  DataManager dataManager { };
  std::string str_func;
  std::vector<std::unique_ptr<Command>> commands { };
  int val = 0;
  while (getline(std::cin, str_func)) {
    for (auto& com : dataManager.knownCommands) {

    }


  }
  return 0;

}