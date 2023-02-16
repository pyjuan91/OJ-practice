#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int N, M, ans = 1e9, cs, a, b, c;
  cin >> N >> M;
  vector<int> cows(105, 0), comp(105, 0);
  vector aircon = vector<vector<int>>(M, vector<int>(4));
  for (int i = 0; i < N; i++) {
    cin >> a >> b >> c;
    for (int j = a; j <= b; j++) cows[j] = c;
  }
  for (int i = 0; i < M; i++)
    for (int j = 0; j < 4; j++) cin >> aircon[i][j];

  for (int i = 0; i < (1 << M); i++) {
    cs = 0;
    vector<int> cv = cows;
    for (int j = 0; j < M; j++) {
      if (i & (1 << j)) {
        cs += aircon[j][3];
        for (int k = aircon[j][0]; k <= aircon[j][1]; k++) {
          if (cv[k]) cv[k] = max(0, cv[k] - aircon[j][2]);
        }
        if (cs > ans) break;
      }
    }
    // for (auto c : cv) cout << c << " ";
    // cout << endl;
    if (cv == comp) ans = min(ans, cs);
  }
  cout << ans << "\n";
  return 0;
}