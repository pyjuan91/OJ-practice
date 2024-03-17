#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int kase = 0, v1, d1, v2, d2;
  const string win_words = "You owe me a beer!\n";
  const string lose_words = "No beer for the captain.\n";
  const string report = "Avg. arrival time: ";
  while (cin >> v1 >> d1 >> v2 >> d2) {
    if (v1 == 0) break;
    cout << "Case #" << ++kase << ": ";
    int t1 = d1 * v2, t2 = d2 * v1;
    if (t1 < t2) cout << win_words;
    else cout << lose_words;
    cout << report;
    int deno = d1*v2 + d2*v1, nomi = v1*v2;
    if (deno % 2 == 0) deno /= 2;
    else nomi *= 2;
    int gg = __gcd(deno, nomi);
    deno /= gg, nomi /= gg;
    cout << deno;
    if (nomi != 1) cout << "/" << nomi;
    cout << "\n";
  }
  return 0;
}