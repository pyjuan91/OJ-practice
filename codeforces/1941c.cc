#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    int cnt_mapie = 0, cnt_map = 0, cnt_pie = 0;
    for (int i = 0; i < n; i++) {
      if (i + 5 <= n && s.substr(i, 5) == "mapei") {
        cnt_mapie++;
        i += 4;
      } else if (i + 3 <= n && s.substr(i, 3) == "map") {
        cnt_map++;
        i += 2;
      } else if (i + 3 <= n && s.substr(i, 3) == "pie") {
        cnt_pie++;
        i += 2;
      }
    }
    // cout << cnt_mapie << ' ' << cnt_map << ' ' << cnt_pie << '\n';
    cout << cnt_mapie + cnt_map + cnt_pie << '\n';
  }
  return 0;
}
