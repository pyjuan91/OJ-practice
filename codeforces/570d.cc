#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 5e5 + 5;
int n, m;
vector<int> tree[kMax];
vector<pair<int, int>> queries[kMax];
int depth[kMax], in_time[kMax], out_time[kMax];
int heavy_child[kMax], subtree_size[kMax];
int timer = 0;
int letter_mask[kMax];
bool answer[kMax];
int idx[kMax];
char letters[kMax];

void dfs(int node, int d) {
  depth[node] = d;
  in_time[node] = ++timer;
  idx[timer] = node;
  subtree_size[node] = 1;
  int max_size = 0;
  for (int child : tree[node]) {
    dfs(child, d + 1);
    subtree_size[node] += subtree_size[child];
    if (subtree_size[child] > max_size) {
      max_size = subtree_size[child];
      heavy_child[node] = child;
    }
  }
  out_time[node] = timer;
}

void add(int node) {
  int d = depth[node];
  int bit = 1 << (letters[node] - 'a');
  letter_mask[d] ^= bit;
}

void add_subtree(int node) {
  for (int i = in_time[node]; i <= out_time[node]; i++) add(idx[i]);
}

void dsu(int node) {
  for (int child : tree[node]) {
    if (child != heavy_child[node]) {
      dsu(child);
      add_subtree(child);
    }
  }

  if (heavy_child[node]) {
    dsu(heavy_child[node]);
  }

  for (int child : tree[node]) {
    if (child != heavy_child[node]) {
      add_subtree(child);
    }
  }

  add(node);
  for (auto [h, i] : queries[node]) {
    int mask = letter_mask[h];
    int count = __builtin_popcount(mask);
    answer[i] = (count <= 1);
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int parent;
    cin >> parent;
    tree[parent].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    cin >> letters[i];
  }

  for (int i = 1; i <= m; i++) {
    int v, h;
    cin >> v >> h;
    queries[v].emplace_back(h, i);
  }

  dfs(1, 1);
  dsu(1);
  for (int i = 1; i <= m; i++) {
    cout << (answer[i] ? "Yes" : "No") << '\n';
  }
  return 0;
}
