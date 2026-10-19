#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
#define double long double
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  double m, h;
  cin >> m >> h;
  double bmi = m / h / h;
  if (bmi < 18.5)
    cout << "Underweight\n";
  else if (bmi < 24)
    cout << "Normal\n";
  else {
    cout << setw(6) << bmi << "\n";
    cout << "Overweight\n";
  }
  return 0;
}
