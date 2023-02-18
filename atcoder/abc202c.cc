#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int n, x;
  long long res = 0;
  cin >> n;
  map<int, vector<int>> b;
  map<int, int> a, c;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a[x] += 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    b[x].emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    c[x] += 1;
  }
  for (auto i : a) {
    if (b.count(i.first))
      for (auto j : b[i.first]) {
        if (c.count(j)) res += 1LL * c[j] * i.second;
      }
  }
  cout << res;
  return 0;
}