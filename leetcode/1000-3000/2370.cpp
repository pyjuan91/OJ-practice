#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestIdealString(string s, int k) {
    int dp[26] = {};
    for (auto c : s) {
      int i = c - 'a';
      int mx = 0;
      for (int j = max(0, i - k); j <= min(25, i + k); j++) {
        mx = max(mx, dp[j] + 1);
      }
      dp[i] = mx;
    }
    return *max_element(dp, dp + 26);
  }
};
int main() {
  string s;
  int k;
  cin >> s >> k;
  Solution sol;
  cout << sol.longestIdealString(s, k) << endl;
}