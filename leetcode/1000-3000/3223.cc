#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumLength(string s) {
    int cnt[26] = { 0 };
    for (auto c : s) {
      cnt[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] >= 3 and cnt[i] % 2 == 1) {
        cnt[i] = 1;
      }
      if (cnt[i] >= 3 and cnt[i] % 2 == 0) {
        cnt[i] = 2;
      }
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
      res += cnt[i];
    }
    return res;
  }
};

int main() {
  Solution solution;
  solution.minimumLength("leetcode");
  return 0;
}