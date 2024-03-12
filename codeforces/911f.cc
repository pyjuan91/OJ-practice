#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
vector<int> g[kMax];
int n, u, v, dia_vertex_1, dia_vertex_2;
int dist_1[kMax] = {}, dist_2[kMax] = {};

void chaewon(int u, int p, int &end_point, int *dist) {
  if (dist[u] > dist[end_point]) end_point = u;
  for (auto v : g[u]) {
    if (v == p) continue;
    dist[v] = dist[u] + 1;
    chaewon(v, u, end_point, dist);
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int dia_vertex_1 = 0, dia_vertex_2 = 0, tmp;

  chaewon(0, -1, dia_vertex_1, dist_1);
  memset(dist_1, 0, sizeof(dist_1));
  chaewon(dia_vertex_1, -1, dia_vertex_2, dist_1);
  chaewon(dia_vertex_2, -1, dia_vertex_1, dist_2);

  int dia_length = dist_1[dia_vertex_2];
  vector<tuple<int, int, int>> extra, in_dia;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int ce = dist_1[i] + dist_2[i] - dia_length;
    if (ce == 0) {
      in_dia.emplace_back(make_tuple(dist_1[i], i, dia_vertex_1));
      res += dist_1[i];
    } else {
      if (dist_1[i] > dist_2[i])
        extra.emplace_back(make_tuple(dist_1[i], i, dia_vertex_1)),
            res += dist_1[i];
      else
        extra.emplace_back(make_tuple(dist_2[i], i, dia_vertex_2)),
            res += dist_2[i];
    }
  }

  sort(extra.begin(), extra.end(),
       [](auto &a, auto &b) { return get<0>(a) > get<0>(b); });
  sort(in_dia.begin(), in_dia.end(),
       [](auto &a, auto &b) { return get<0>(a) > get<0>(b); });
  in_dia.pop_back();
  cout << res << '\n';
  for (auto [d, u, v] : extra)
    cout << u + 1 << " " << v + 1 << " " << u + 1 << "\n";
  for (auto [d, u, v] : in_dia)
    cout << u + 1 << " " << v + 1 << " " << u + 1 << "\n";
  return 0;
}
