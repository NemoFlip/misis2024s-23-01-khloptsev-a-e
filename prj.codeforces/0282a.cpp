#include <iostream>

int main() {
  int n = 0;
  std::cin >> n;
  int res = 0;
  for (int i = 0; i < n; i += 1) {
    char inp;
    std::cin >> inp;
    if (inp == 'X') { // Если запись вида X++
      std::cin >> inp;
      if (inp == '+') {
        res += 1;
      } else {
        res -= 1;
      }
      std::cin >> inp;
    } else { // Если запись вида ++X
      if (inp == '+') {
        res += 1;
      } else {
        res -= 1;
      }
      std::cin >> inp;
      std::cin >> inp;
    }
  }
  std::cout << res;
  return 0;
}