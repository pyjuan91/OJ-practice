#include <algorithm>
#include <cctype>
#include <iostream>

int main() {
  std::string s;
  std::cin >> s;

  bool isCapitalized = std::isupper(s[0]) &&
                       std::all_of(s.begin() + 1, s.end(), [](unsigned char c) {
                         return std::islower(c);
                       });

  std::cout << (isCapitalized ? "Yes" : "No") << '\n';

  return 0;
}