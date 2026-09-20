#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    string s = to_string(n);
    int m = s.size();
    vector dp(m, vector(m + 1, -1));

    auto dfs = [&](this auto& dfs, int idx, int cnt, bool is_limit) -> int {
      if (idx == m) return cnt;
      if (not is_limit and dp[idx][cnt] != -1) return dp[idx][cnt];
      int res = 0;
      int up = is_limit ? (s[idx] - '0') : 9;
      for (int i = 0; i <= up; i++) {
        res += dfs(idx + 1, cnt + (i == 1), is_limit and i == up);
      }
      if (not is_limit) dp[idx][cnt] = res;
      return res;
    };

    return dfs(0, 0, true);
  }
};

int main() { return 0; }