#include <bits/stdc++.h>
using namespace std;
int calDiff(vector<int>& a) {
  int res{0};
  for (int i = 0; i < a.size(); i += 2) res += a[i + 1] - a[i];
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n, res = 1e9;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      vector tmp = a;
      tmp.erase(tmp.begin() + j);
      tmp.erase(tmp.begin() + i);
      res = min(res, calDiff(tmp));
    }
  }
  cout << res << "\n";
  return 0;
}