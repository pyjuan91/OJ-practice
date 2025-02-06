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
  int64_t maximumCoins(vector<vector<int32_t>>& org_coins, int32_t k) {
    vector<array<int64_t, 3>> coins;
    coins.reserve(org_coins.size());
    transform(org_coins.begin(), org_coins.end(), back_inserter(coins), [](const vector<int32_t>& coin) {
      return array<int64_t, 3>{coin[0], coin[1], coin[2]};
      });
    sort(coins.begin(), coins.end());

    int64_t res = 0, sum = 0;
    for (size_t i = 0, j = 0; i < coins.size(); i++) {
      while (j < coins.size() and coins[j][1] < coins[i][0] + k) {
        sum += coins[j][2] * (coins[j][1] - coins[j][0] + 1);
        j++;
      }
      res = max(res, sum);
      if (j < coins.size()) {
        int64_t partial = max(int64_t(0), (coins[i][0] + k - coins[j][0]) * coins[j][2]);
        res = max(res, sum + partial);
      }
      sum -= coins[i][2] * (coins[i][1] - coins[i][0] + 1);
    }

    sum = 0;
    for (size_t i = coins.size() - 1, j = coins.size() - 1; i < coins.size(); i--) {
      while (j < coins.size() and coins[i][1] - coins[j][0] < k) {
        sum += coins[j][2] * (coins[j][1] - coins[j][0] + 1);
        j--;
      }
      res = max(res, sum);
      if (j < coins.size()) {
        int64_t partial = max(int64_t(0), (coins[j][1] + k - coins[i][1]) * coins[j][2]);
        res = max(res, sum + partial);
      }
      sum -= coins[i][2] * (coins[i][1] - coins[i][0] + 1);
    }

    return res;
  }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> coins(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> coins[i][j];
    }
  }
  Solution sol;
  cout << sol.maximumCoins(coins, k) << '\n';
  return 0;
}
