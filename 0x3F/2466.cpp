#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    const int kMod = 1e9 + 7;
    int res = 0;
    vector<int> dp(high + 1);
    dp[0] = 1;

    for (int i = 1; i <= high; i++) {
      if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % kMod;
      if (i >= one) dp[i] = (dp[i] + dp[i - one]) % kMod;
      if (i >= low) res = (res + dp[i]) % kMod;
    }

    return res;
  }
};

int main() { return 0; }