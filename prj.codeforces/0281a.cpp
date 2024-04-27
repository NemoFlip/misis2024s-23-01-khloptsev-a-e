#include <iostream>
#include <string>
int main() {
  std::string s;
  std::cin >> s;
  char first_letter = static_cast<char>(s[0]);
  s = s.substr(1);
  if (first_letter > 90) {
    first_letter -= 32;
  }
  std::cout << first_letter << s;
  return 0;
}