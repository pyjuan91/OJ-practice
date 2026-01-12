#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestBalanced(string s) {
    int n = s.size();
    vector<vector<int>> prefix(26, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
      int idx = s[i - 1] - 'a';
      for (int j = 0; j < 26; j++) prefix[j][i] = prefix[j][i - 1];
      prefix[idx][i]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        int cnt = -1;
        bool is_balanced = true;
        for (int k = 0; k < 26; k++) {
          if (prefix[k][j] - prefix[k][i] > 0) {
            if (cnt == -1)
              cnt = prefix[k][j] - prefix[k][i];
            else if (cnt != prefix[k][j] - prefix[k][i])
              is_balanced = false;
          }
        }
        if (is_balanced) res = max(res, j - i);
      }
    }
    return res;
  }
};

int main() { return 0; }