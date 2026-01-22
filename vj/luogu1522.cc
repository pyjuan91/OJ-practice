#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pair<int, int>> cor;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    cor.push_back(make_pair(x, y));
  }

  auto get_dist = [&](int i, int j) -> double {
    return sqrt(pow((cor[i].first - cor[j].first), 2) +
                pow((cor[i].second - cor[j].second), 2));
  };

  constexpr double kMax = static_cast<double>(INT64_MAX >> 1);
  vector<vector<double>> dist(n, vector<double>(n, kMax));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < n; j++) {
      if (j == i) dist[i][j] = 0;
      if (s[j] == '1') dist[i][j] = get_dist(i, j);
    }
  }

  for (int k = 0; k < n; k++) {
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
      }
    }
  }

  vector<double> ma_dist(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] != kMax) {
        ma_dist[i] = max(ma_dist[i], dist[i][j]);
      }
    }
  }

  vector<int> comp(n);
  int idx_comp = 1;

  for (int i = 0; i < n; i++) {
    if (comp[i] == 0) {
      for (int j = 0; j < n; j++) {
        if (dist[i][j] < kMax) comp[j] = idx_comp;
      }
      idx_comp++;
    }
  }

  vector<double> comp_diameter(idx_comp);
  for (int i = 0; i < n; i++) {
    comp_diameter[comp[i]] = max(comp_diameter[comp[i]], ma_dist[i]);
  }

  double res = kMax;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (dist[i][j] < kMax) continue;
      double temp = max({ma_dist[i] + ma_dist[j] + get_dist(i, j),
                         comp_diameter[comp[i]], comp_diameter[comp[j]]});
      res = min(res, temp);
    }
  }

  cout << fixed << setprecision(6) << res << "\n";
  return 0;
}
