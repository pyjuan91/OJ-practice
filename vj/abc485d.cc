#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int haerin(int n, string& s) {
  vector<vector<int>> suffix(3, vector<int>(n, 0));
  for (int i = n - 1; i >= 0; i--) {
    suffix[s[i] - 'A'][i]++;
    if (i < n - 1) {
      for (int j = 0; j < 3; j++) suffix[j][i] += suffix[j][i + 1];
    }
  }
  int res = 0;
  int i1 = -1;
  vector<int> last(3, -1);
  bitset<3> cnt;
  for (int i = 0; i < n; i++) {
    cnt.set(s[i] - 'A', true);
    last[s[i] - 'A'] = i;
    if (cnt.all()) {
      i1 = i;
      break;
    }
  }
  debug(i1);
  if (i1 == -1) return 0;

  for (int i = i1 + 1; i + 3 < n; i++) {
    if (suffix[0][i + 1] == 0 or suffix[1][i + 1] == 0 or suffix[2][i + 1] == 0)
      break;
    last[s[i] - 'A'] = i;
    int rb = *min_element(last.begin(), last.end());
    if (rb > i1) res += rb - i1;
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  cout << haerin(n, s) << "\n";
  return 0;
}
