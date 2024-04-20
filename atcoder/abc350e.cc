#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int precised_floor(double x) { return (int)floor(x + 1e-9); }

const int kMax = 2e5 + 1;

unordered_map<int, double> dp;

double kazuha(int N, int A, int X, int Y) {
  if (dp.count(N)) return dp[N];

  if (N == 0) return 0;

  double select_plan_A = kazuha(N / A, A, X, Y) + X;
  double select_plan_B = Y;
  for (int dice = 6; dice >= 2; dice--) {
    select_plan_B += kazuha(precised_floor((double)N / dice), A, X, Y) + Y;
  }
  // cout << N << ' ' << select_plan_A << ' ' << select_plan_B << '\n';
  select_plan_B /= 5;
  return dp[N] = min(select_plan_A, select_plan_B);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int N, A, X, Y;
  cin >> N >> A >> X >> Y;
  cout << fixed << setprecision(10) << kazuha(N, A, X, Y) << '\n';
  return 0;
}
