#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution {
public:
  int waysToReachStair(int k) {
    if (k == 0) return 2;
    if (k == 1) return 4;
    auto nCr = [&](int n, int r) {
      if (r > n - r) {
        r = n - r;
      }
      int64_t res = 1;
      for (int i = 0; i < r; i++) {
        res *= n - i;
        res /= i + 1;
      }
      return (int32_t)res;
      };
    int res = 0;
    int64_t stairs = 1;
    for (int jump = 0; jump <= 32; jump++) {
      stairs += 1LL << jump;
      if (stairs < k) continue;
      int64_t required = stairs - k;
      if (required > jump + 2) break;
      res += nCr(jump + 2, (int32_t)required);
    }
    return res;
  }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int k;
  cin >> k;
  Solution solution;
  cout << solution.waysToReachStair(k) << '\n';
  return 0;
}
