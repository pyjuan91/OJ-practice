#include <bits/stdc++.h>
using namespace std;
class Solution {
 private:
  int64_t check(vector<int>& coins, int64_t candidate) {
    int n = coins.size();
    int64_t res = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
      int64_t cores_lcm = 1;
      for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) cores_lcm = lcm(cores_lcm, coins[i]);
      }
      if (__popcount(mask) & 1) {
        res += candidate / cores_lcm;
      } else {
        res -= candidate / cores_lcm;
      }
    }
    return res;
  }

 public:
  long long findKthSmallest(vector<int>& coins, int k) {
    int64_t left = 0, right = 1e18, mid;
    while (left + 1 < right) {
      mid = (left + right) / 2;
      if (check(coins, mid) >= (int64_t)k) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  }
};
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  Solution s;
  cout << s.findKthSmallest(coins, k) << endl;
  return 0;
}