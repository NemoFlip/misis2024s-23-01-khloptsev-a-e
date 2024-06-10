#include <iostream>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  for (int i = 0; i < k; i += 1) {
    if (n % 10 != 0) {
      n -= 1;
    } else {
      n /= 10;
    }
  }
  std::cout << n << std::endl;

  return 0;
}