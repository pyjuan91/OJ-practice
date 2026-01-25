#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int vowelConsonantScore(string s) {
    array<char, 5> vowels = {'a', 'e', 'i', 'o', 'u'};
    auto is_vowels = [&](const char& c) -> bool {
      for (int i = 0; i < 5; i++) {
        if (c == vowels[i]) return true;
      }
      return false;
    };
    int v = 0, c = 0;
    for (const auto& ch : s) {
      if (is_vowels(ch))
        v++;
      else if (isalpha(ch))
        c++;
    }
    if (c == 0) return 0;
    return v / c;
  }
};

int main() { return 0; }