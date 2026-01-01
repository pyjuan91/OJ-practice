#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximizeWin(vector<int>& prizePositions, int k) {
    int n = prizePositions.size();
    vector<int> dp(n);

    int left_index = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
      while (left_index <= i and
             prizePositions[i] - prizePositions[left_index] > k)
        left_index++;
      if (i == 0)
        dp[0] = res = 1;
      else {
        dp[i] = max(dp[i - 1], i - left_index + 1);
        res = max(res, (left_index ? dp[left_index - 1] : 0) + i - left_index + 1);
      }
    }

    return res;
  }
};

int main() { return 0; }