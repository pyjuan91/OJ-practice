#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> res;
  vector<bool> rp, diag, antid;
  vector<pair<int, int>> rec;
  void record(int n) {
    vector<string> ans(n, string(n, '.'));
    for (auto p : rec) ans[p.first][p.second] = 'Q';
    res.push_back(ans);
  }
  void go(int cc, int n) {
    if (cc == n) {
      record(n);
      return;
    }
    for (int i = 0; i < n; i++) {
      if (rp[i] || diag[cc + i] || antid[i - cc + n]) continue;
      rp[i] = diag[cc + i] = antid[i - cc + n] = true;
      rec.push_back({cc, i});
      go(cc + 1, n);
      rp[i] = diag[cc + i] = antid[i - cc + n] = false;
      rec.pop_back();
    }
  }
  vector<vector<string>> solveNQueens(int n) {
    res.clear();
    rp.resize(n, false);
    diag.resize(2 * n + 5, false);
    antid.resize(2 * n + 5, false);
    go(0, n);
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  Solution s;
  vector<vector<string>> a = s.solveNQueens(n);
  for (auto i : a) {
    for (auto j : i) cout << j << " ";
    cout << endl;
  }
  return 0;
};