#include <bits/stdc++.h>
using namespace std;
const int kMax = 501;
struct MaxFlow {
  struct Edge {
    int v, nxt, cap, flow;
  } edge[kMax];

  int fir[kMax], cnt;
  int n, S, T;
  int64_t max_flow;
  int dep[kMax], cur[kMax];

  void init() {
    memset(fir, -1, sizeof(fir));
    cnt = max_flow = 0;
  }

  void add_edge(int u, int v, int cap, bool directed = true) {
    edge[cnt] = {v, fir[u], cap, 0};
    fir[u] = cnt++;
    edge[cnt] = {u, fir[v], directed ? 0 : cap, 0};
    fir[v] = cnt++;
  }

  bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (n + 1));
    dep[S] = 1;
    q.push(S);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = fir[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if (!dep[v] && edge[i].cap > edge[i].flow) {
          dep[v] = dep[u] + 1;
          q.push(v);
        }
      }
    }
    return dep[T];
  }

  int dfs(int u, int flow) {
    if (u == T || !flow) return flow;
    int res = 0;
    for (int &i = cur[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].v;
      if (dep[v] == dep[u] + 1 && edge[i].cap > edge[i].flow) {
        int f = dfs(v, min(flow, edge[i].cap - edge[i].flow));
        if (f) {
          edge[i].flow += f;
          edge[i ^ 1].flow -= f;
          res += f;
          flow -= f;
          if (!flow) break;
        }
      }
    }
    return res;
  }

  void dinic() {
    while (bfs()) {
      memcpy(cur, fir, sizeof(int) * (n + 1));
      max_flow += dfs(S, INT_MAX);
    }
  }
};