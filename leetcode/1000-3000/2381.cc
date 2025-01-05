#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    size_t n = s.size();
    vector<int> prefix_changes(n + 1);
    for (auto& shift : shifts) {
      int start = shift[0], end = shift[1], change = shift[2];
      if (change) {
        prefix_changes[start]++;
        prefix_changes[end + 1]--;
      }
      else {
        prefix_changes[start]--;
        prefix_changes[end + 1]++;
      }
    }

    const int kMax = 5e4 + 5;
    const int kMod = 26;

    auto shift_char = [](char c, int shift) {
      return (c - 'a' + shift + kMax * kMod) % kMod + 'a';
      };

    for (size_t i = 0; i < n; i++) {
      if (i) prefix_changes[i] += prefix_changes[i - 1];
      s[i] = shift_char(s[i], prefix_changes[i]);
    }

    return s;
  }
};

int main() {
  return 0;
}