#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e5 + 5;

struct MaxFlow {
  struct Edge {
    int v, nxt, cap, flow;
  } edge[kMax];

  int head[kMax], cnt;

  int n, S, T;
  int64_t max_flow;
  int depth[kMax], cur[kMax];

  void init() {
    memset(head, -1, sizeof(head));
    cnt = 0, max_flow = 0LL;
  }

  void add_edge(int u, int v, int cap) {
    edge[cnt] = {v, head[u], cap, 0};
    head[u] = cnt++;
    edge[cnt] = {u, head[v], 0, 0};
    head[v] = cnt++;
  }

  bool bread_first_search() {
    queue<int> q;
    memset(depth, 0, sizeof(int) * (n + 1));

    depth[S] = 1;
    q.push(S);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if (!depth[v] && edge[i].cap > edge[i].flow) {
          depth[v] = depth[u] + 1;
          q.push(v);
        }
      }
    }
    return depth[T];
  }

  int depth_first_search(int u, int flow) {
    if (u == T || !flow) return flow;
    int res = 0;
    for (int &i = cur[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].v;
      if (depth[v] == depth[u] + 1 && edge[i].cap > edge[i].flow) {
        int d =
            depth_first_search(v, min(flow - res, edge[i].cap - edge[i].flow));
        res += d;
        edge[i].flow += d;
        edge[i ^ 1].flow -= d;
        if (res == flow) break;
      }
    }
    return res;
  }

  void dinic() {
    while (bread_first_search()) {
      memcpy(cur, head, sizeof(int) * (n + 1));
      max_flow += 1LL * depth_first_search(S, INT_MAX);
    }
  }

} max_flow;