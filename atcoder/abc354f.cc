#include <bits/stdc++.h>
using namespace std;

const int kMax = 2e5 + 5;
int t, n, a[kMax], dp[kMax];
int seg[4 * kMax];
set<int> val_idx[kMax];
bool is_part_of_LIS[kMax];

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    seg[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm) {
    update(v * 2, tl, tm, pos, val);
  } else {
    update(v * 2 + 1, tm + 1, tr, pos, val);
  }
  seg[v] = max(seg[v * 2], seg[v * 2 + 1]);
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return seg[v];
  int tm = (tl + tr) / 2;
  return max(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void discreate_value() {
  vector<int> b(a + 1, a + n + 1);
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 2;
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    discreate_value();
    // clear segment tree and dp
    for (int i = 1; i <= n + 1; i++) {
      update(1, 1, n, i, 0);
      dp[i] = 0;
      val_idx[i].clear();
      is_part_of_LIS[i] = false;
    }

    for (int i = 1; i <= n; i++) {
      dp[i] = query(1, 1, n, 1, a[i] - 1) + 1;
      update(1, 1, n, a[i], dp[i]);
    }

    int LIS = *max_element(dp + 1, dp + n + 1);
    for (int i = n; i >= 1; i--) {
      if (dp[i] == LIS) {
        is_part_of_LIS[i] = true;
        val_idx[dp[i]].insert(a[i]);
      } else {
        auto it = val_idx[dp[i] + 1].upper_bound(a[i]);
        if (it != val_idx[dp[i] + 1].end()) {
          val_idx[dp[i]].insert(a[i]);
          is_part_of_LIS[i] = true;
        }
      }
    }

    int total = 0;
    for (int i = 1; i <= n; i++) {
      total += is_part_of_LIS[i];
    }
    cout << total << '\n';
    for (int i = 1; i <= n; i++) {
      if (is_part_of_LIS[i]) {
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
