#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 1005;
long double dp_princess[kMax][kMax], dp_dragon[kMax][kMax];

long double princess_win(int n, int m);
long double dragon_win(int n, int m);

long double dragon_win(int n, int m) {
  if (n == 0 || m == 0) return 1.0;
  if (dp_dragon[n][m] != -1.0) return dp_dragon[n][m];
  long double res = 0.0;
  // wining at this round
  res += 1.0 * n / (n + m);
  // wining later (this round n jumps out one mouse)
  if (m > 1) {
    res += 1.0 * m / (n + m) * (1.0 * n / (n + m - 1)) *
           (1.0 - princess_win(n - 1, m - 1));
    res += 1.0 * m / (n + m) * (1.0 * (m - 1) / (n + m - 1)) *
           (1.0 - princess_win(n, m - 2));
  } else {
    res += 1.0 * m / (n + m) * (1.0 - princess_win(n - 1, m - 1));
  }
  return dp_dragon[n][m] = res;
}

long double princess_win(int n, int m) {
  if (n == 0) return 0.0;
  if (m == 0) return 1.0;
  if (dp_princess[n][m] != -1.0) return dp_princess[n][m];
  long double res = 0.0;
  // wining at this round
  res += 1.0 * n / (n + m);
  // cout << "winning at this round: " << res << '\n';
  // wining later
  res += 1.0 * m / (n + m) * (1.0 - dragon_win(n, m - 1));
  // cout << "winning later: " << res << '\n';
  return dp_princess[n][m] = res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 0; i < kMax; ++i)
    for (int j = 0; j < kMax; ++j) dp_princess[i][j] = dp_dragon[i][j] = -1.0;
  int n, m;
  cin >> n >> m;
  cout << fixed << setprecision(9) << princess_win(n, m) << '\n';
  return 0;
}
