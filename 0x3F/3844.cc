#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int almostPalindromic(string s) {
    const int n = s.size();
    int res = 0;
    auto is_palin = [&](int l, int r) -> bool {
      while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
      }
      return true;
    };

    auto check = [&](int l, int r) -> int {
      int left = l, right = r;
      while (left < right) {
        if (s[left] != s[right]) {
          if (is_palin(left + 1, right) || is_palin(left, right - 1))
            return r - l;
          return -1;
        }
        left++;
        right--;
      }
      return r - l;
    };

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (j - i <= res) continue;
        int val = check(i, j);
        res = max(res, val);
      }
    }
    return res + 1;
  }
};

int main() { return 0; }