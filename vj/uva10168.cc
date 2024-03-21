#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 1e7 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

void init() {
  for (int i = 2; i <= kMax; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= kMax; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }
}

vector<pair<int, int>> res(kMax, make_pair(0LL, 0LL));
vector<tuple<int, int, int, int>> ans(kMax, make_tuple(0, 0, 0, 0));

pair<int, int> kazuha(int n) {
  if (res[n] != make_pair(0LL, 0LL)) {
    return res[n];
  }
  res[n] = make_pair(-1LL, -1LL);
  if (n % 2 == 1) {
    if (lp[n - 2] == n - 2) {
      res[n] = make_pair(2, n - 2);
    }
  } else {
    for (int i = 0; i < pr.size() && pr[i] <= n / 2; i++) {
      if (lp[n - pr[i]] == n - pr[i]) {
        res[n] = make_pair(pr[i], n - pr[i]);
        break;
      }
    }
  }
  return res[n];
}

void woogie(int n) {
  if (ans[n] != make_tuple(0, 0, 0, 0)) {
    cout << get<0>(ans[n]) << " " << get<1>(ans[n]) << " " << get<2>(ans[n])
         << " " << get<3>(ans[n]) << "\n";
    return;
  }
  for (int i = 4; i <= n / 2; i++) {
    pair<int, int> p1 = kazuha(i);
    pair<int, int> p2 = kazuha(n - i);
    if (p1.first != -1 && p2.first != -1) {
      ans[n] = make_tuple(p1.first, p1.second, p2.first, p2.second);
      cout << p1.first << " " << p1.second << " " << p2.first << " " << p2.second
           << "\n";
      return;
    }
  }
  cout << "Impossible.\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int n;
  while (cin >> n) {
    woogie(n);
  }
  return 0;
}
