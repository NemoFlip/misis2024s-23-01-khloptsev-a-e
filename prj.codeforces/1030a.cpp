#include <iostream>

int main() {
  int n = 0;
  int inp = 0;
  std::cin >> n;
  for (int i = 0; i < n; i += 1) {
    std::cin >> inp;
    if (inp == 1) {
      std::cout << "HARD";
      return 0;
    }
  }
  std::cout << "EASY";
  return 0;
}