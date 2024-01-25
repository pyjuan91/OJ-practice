#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, x;
  cin >> n;
  vector<int> a(n + 1), fenwick(n + 1, 0);

  auto update = [&](int i, int x) {
    for (; i <= n; i += i & -i) fenwick[i] += x;
  };
  auto get_sum_index = [&](int sum) {
    int res = 0;
    for (int i = 1 << __lg(n); i; i >>= 1)
      if (res + i <= n && fenwick[res + i] < sum) sum -= fenwick[res += i];
    return res + 1;
  };

  for (int i = 1; i <= n; i++) cin >> a[i], update(i, 1);
  for (int i = 1; i <= n; i++) {
    cin >> x;
    int index = get_sum_index(x);
    cout << a[index] << ' ';
    update(index, -1);
  }
  return 0;
}
