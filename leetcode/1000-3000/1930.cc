#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    size_t n = s.size();
    vector<vector<int>> positions(26);
    for (size_t i = 0; i < n; i++) {
      positions[s[i] - 'a'].push_back(i);
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (positions[i].size() < 2) continue;
      if (positions[i].size() > 2) res++;
      for (int j = 0; j < 26; j++) {
        if (positions[j].empty() or j == i) continue;
        auto it = lower_bound(positions[j].begin(), positions[j].end(), positions[i][0]);
        if (it != positions[j].end() and *it < positions[i].back()) res++;
      }
    }

    return res;
  }
};

int main() {
  return 0;
}