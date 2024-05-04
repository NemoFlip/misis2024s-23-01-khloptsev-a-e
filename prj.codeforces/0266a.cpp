#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  char inp;
  int res = 0;
  std::cin >> inp;
  for (int i = 0; i < n - 1; ++i) {
    char next;
    std::cin >> next;
    if (next == inp) {
      res += 1;
    }
    inp = next;
  }
  std::cout << res;
  return 0;
}
