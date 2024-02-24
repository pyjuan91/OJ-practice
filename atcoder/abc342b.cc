#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  int m;
  cin >> m;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (pos[a] < pos[b])
      cout << a << "\n";
    else
      cout << b << "\n";
  }
  return 0;
}
