#include <bits/stdc++.h>
using namespace std;

int chaewon(int n, vector<int>& a, int id) {
  vector<bool> reach(105, false);
  reach[0] = true;
  for (int i = 1; i <= n; i++) {
    vector<bool> new_reach = reach;
    for (int j = 0; j <= id; j++) {
      for (int k = 104; k >= 0; k--) {
        if (k + a[j] <= 104 && reach[k]) {
          new_reach[k + a[j]] = true;
        }
      }
    }
    swap(reach, new_reach);
  }
  for (int i = 1; i <= 104; i++) {
    if (!reach[i]) return i - 1;
  }
  return 104;
}

void kazuha(int n, int m, vector<int>& a, vector<int>& mr, vector<int>& res,
            int id) {
  for (int candi = a[id - 1] + 1; candi <= mr[id - 1] + 1; candi++) {
    a[id] = candi;
    int max_reach = chaewon(n, a, id);
    if (max_reach > mr[id]) {
      mr[id] = max_reach;
      if (id == m - 1) res = a;
    }
    if (id < m - 1) kazuha(n, m, a, mr, res, id + 1);
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m && n) {
    vector<int> a(m), max_reach(m), res(m);
    a[0] = 1, max_reach[0] = n, res[0] = 1;
    kazuha(n, m, a, max_reach, res, 1);
    for (auto x : res) cout << setw(3) << x;
    cout << " ->" << setw(3) << max_reach[m - 1] << '\n';
  }
  return 0;
}
