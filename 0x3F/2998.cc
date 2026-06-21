#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    const int kMax = 1e5 + 5;
    vector<int> dp(kMax, -1);
    dp[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
      int cur = q.front();
      if (cur == y) return dp[cur];
      q.pop();
      if (cur % 11 == 0 and dp[cur / 11] == -1) {
        dp[cur / 11] = dp[cur] + 1;
        q.push(cur / 11);
      }
      if (cur % 5 == 0 and dp[cur / 5] == -1) {
        dp[cur / 5] = dp[cur] + 1;
        q.push(cur / 5);
      }
      if (cur + 1 < kMax and dp[cur + 1] == -1) {
        dp[cur + 1] = dp[cur] + 1;
        q.push(cur + 1);
      }
      if (cur - 1 >= 0 and dp[cur - 1] == -1) {
        dp[cur - 1] = dp[cur] + 1;
        q.push(cur - 1);
      }
    }
    return -1;
  }
};

int main() { return 0; }