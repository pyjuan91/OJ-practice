#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n) {
  if (n == (1LL << __lg(n))) {
    cout << "-1\n";
    return;
  }
  if (n % 2 == 1) {
    vector<int> a(n + 1);
    a[1] = n - 1, a[n - 1] = n, a[n] = 1;
    for (int i = 2; i < n - 1; i += 2) a[i] = i + 1, a[i + 1] = i;
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
  } else {
    vector<int> a(n + 1);
    a[1] = n, a[n] = 1;
    for (int i = 2; i < n; i += 2) a[i] = i + 1, a[i + 1] = i;
    int remain = n % (1LL << __lg(n));
    swap(a[1], a[remain]);
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    patty(n);
  }
  return 0;
}
