#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, a[kMax], b[kMax] = {}, res = 0;

int32_t main() {
  const int N = kMax;
  vector<int> lp(N + 1);
  vector<int> pr;

  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }

  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1 || a[i] == 0) {
      b[a[i]]++;
      continue;
    }
    int shrink_a = 1, prev = 0, cnt = 0;
    while (a[i] > 1) {
      if (lp[a[i]] == prev)
        cnt++;
      else {
        if (cnt & 1) shrink_a *= prev;
        prev = lp[a[i]];
        cnt = 1;
      }
      a[i] /= lp[a[i]];
    }
    if (cnt & 1) shrink_a *= prev;
    // cout << shrink_a << " ";
    b[shrink_a]++;
  }

  for (int i = 1; i < kMax; i++) {
    res += b[i] * (b[i] - 1) / 2;
  }
  res += b[0] * (b[0] - 1) / 2;
  res += b[0] * (n - b[0]);
  cout << res << "\n";
  return 0;
}
