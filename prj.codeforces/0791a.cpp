#include <iostream>

int main() {
  int a = 0; // вес Лимака
  int b = 0; // вес Боба
  std::cin >> a >> b;
  int res = 0;
  while (a <= b) {
    a *= 3;
    b *= 2;
    ++res;
  }
  std::cout << res;
  return 0;
}