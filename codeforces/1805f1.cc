#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 3005, kMod = 1e9 + 7;
int n, a[kMax], b[kMax], bi_pow[kMax], ans = 0;

struct PairIndex {
  int i, j;
  PairIndex(int i, int j) : i(i), j(j) {}
  bool operator<(const PairIndex& other) const {
    return a[i] + a[j] >= a[other.i] + a[other.j];
  }
};
priority_queue<PairIndex> pq;

void init_bi_pow() {
  bi_pow[0] = 1;
  for (int i = 1; i < kMax; i++) bi_pow[i] = bi_pow[i - 1] * 2 % kMod;
}

void sub_update(int n) {
  ans = (ans + a[1] * bi_pow[n - 1]) % kMod;
  for (int i = 2; i <= n; i++) a[i] -= a[1];
  a[1] = 0;
}

void woogie(int n) {
  while (!pq.empty()) pq.pop();
  for (int i = 2; i <= n; i++) pq.push(PairIndex(i - 1, i));
  for (int i = 2; i <= n; i++) {
    PairIndex p = pq.top();
    pq.pop();
    b[i] = a[p.i] + a[p.j];
    pq.push(PairIndex(p.i, p.j + 1));
  }
  for (int i = 1; i < n; i++) a[i] = b[i + 1];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init_bi_pow();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 2; i--) {
    sub_update(i);
    woogie(i);
  }
  cout << (ans + a[1]) % kMod << '\n';
  return 0;
}
