#include <bits/stdc++.h>
#define int long long
using namespace std;

class BIT {
 private:
  std::vector<int> bit;  // Binary indexed tree
 public:
  BIT(int n) { bit = std::vector<int>(n + 1, 0); }

  void update(int idx, int val) {
    for (; idx < bit.size(); idx += idx & -idx) bit[idx] += val;
  }

  void range_update(int l, int r, int val) {
    update(l, val);
    update(r + 1, -val);
  }

  int point_query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
  }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m, x, y, z, k;
  cin >> n >> m;
  auto bit = BIT(n);
  for (int i = 0; i < n; i++) {
    cin >> x, bit.range_update(i + 1, i + 1, x);
  }

  while (m--) {
    cin >> x;
    x++;
    y = bit.point_query(x);
    bit.range_update(x, x, -y);
    z = y / n;
    k = y % n;
    if (z) bit.range_update(1, n, z);
    if (k) {
      if (n - x >= k)
        bit.range_update(x + 1, x + k, 1);
      else {
        bit.range_update(x + 1, n, 1);
        bit.range_update(1, k - (n - x), 1);
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << bit.point_query(i) << ' ';
  cout << '\n';
  return 0;
}