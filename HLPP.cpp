#include <bits/stdc++.h>

template <class T>
struct HLPP {
  const T INF = ~0u >> 1;
  struct edge {
    int to, rev;
    T f;
  };
  std::vector<edge> edges;
  int maxn, s, t;
  std::vector<int> first_edge;
  std::vector<int> _cur_edge;
  std::vector<int> nxt;
  std::vector<int> lst;
  std::vector<T> excess;
  std::vector<int> arc;
  std::vector<int> gapNxt;
  std::vector<int> gapPrv;
  std::vector<int> height;
  int highest, highestGap, work, eax;
  std::vector<int> q;
  HLPP(std::vector<int> &degrees, int MAXN, int MAXM) {
    edges.assign(MAXM << 1, {});
    first_edge.assign(MAXN + 1, 0);
    _cur_edge.assign(MAXN, 0);
    nxt.assign(MAXN, 0);
    lst.assign(MAXN, 0);
    excess.assign(MAXN, 0);
    arc.assign(MAXN, 0);
    gapNxt.assign(MAXN << 1, 0);
    gapPrv.assign(MAXN << 1, 0);
    height.assign(MAXN, 0);
    q.assign(MAXM << 1, 0);
    maxn = degrees.size();
    eax = (std::__lg(MAXM + 1) * MAXN) >> 1;
    int cnt(0);

    for (int i(0); i < maxn; ++i) {
      first_edge[i] = cnt;
      cnt += degrees[i];
    }

    first_edge[maxn] = cnt;
    std::copy(first_edge.begin(), first_edge.begin() + maxn + 1,
              _cur_edge.begin());
  }
  inline void addEdge(int from, int to, int f, bool isDirected = true) {
    edges[_cur_edge[from]++] = {to, _cur_edge[to], f};
    edges[_cur_edge[to]++] = {from, _cur_edge[from] - 1, isDirected ? 0 : f};
  }
  inline void pushLst(int h, int v) {
    nxt[v] = lst[h];
    lst[h] = v;
  }
  inline void updHeight(int v, int nh) {
    if (height[v] != maxn) {
      gapNxt[gapPrv[v]] = gapNxt[v];
      gapPrv[gapNxt[v]] = gapPrv[v];
    }

    height[v] = nh;

    if (nh == maxn) return;

    highestGap = std::max(highestGap, nh);

    if (excess[v] > 0) {
      highest = std::max(highest, nh);
      pushLst(nh, v);
    }

    nh += maxn;
    gapNxt[v] = gapNxt[nh];
    gapPrv[v] = nh;
    gapNxt[nh] = v;
    gapPrv[gapNxt[v]] = v;
  }
  inline void globalRelabel() {
    work = 0;
    std::fill(height.begin(), height.begin() + maxn, maxn);
    std::fill(lst.begin(), lst.begin() + maxn, -1);
    std::iota(gapNxt.begin(), gapNxt.begin() + maxn, 0);
    std::iota(gapPrv.begin(), gapPrv.begin() + maxn, 0);
    height[t] = 0;
    q[0] = t;

    for (int i(0), sz(1); i < sz; ++i) {
      int v = q[i];

      for (int ie = first_edge[v]; ie < first_edge[v + 1]; ++ie) {
        auto &e = edges[ie];

        if (height[e.to] == maxn && edges[e.rev].f > 0)
          q[sz++] = e.to, updHeight(e.to, height[v] + 1);
      }

      highest = highestGap = height[v];
    }
  }
  inline void push(int v, edge &e) {
    T df = std::min(excess[v], e.f);

    if (df > 0) {
      if (!excess[e.to]) pushLst(height[e.to], e.to);

      e.f -= df, edges[e.rev].f += df;
      excess[v] -= df, excess[e.to] += df;
    }
  }
  inline void discharge(int v) {
    int nh = maxn;

    for (int i(arc[v]); i < first_edge[v + 1]; ++i) {
      auto &e = edges[i];

      if (e.f > 0) {
        if (height[v] == height[e.to] + 1) {
          push(v, e);

          if (excess[v] <= 0) {
            arc[v] = i;
            return;
          }
        } else
          nh = std::min(nh, height[e.to] + 1);
      }
    }

    for (int i(first_edge[v]); i < arc[v]; ++i) {
      auto &e = edges[i];

      if (e.f > 0) {
        if (height[v] == height[e.to] + 1) {
          push(v, e);

          if (excess[v] <= 0) {
            arc[v] = i;
            return;
          }
        } else
          nh = std::min(nh, height[e.to] + 1);
      }
    }

    ++work;

    if (gapNxt[gapNxt[height[v] + maxn]] != height[v] + maxn) {
      updHeight(v, nh);
    } else {
      int oldH = height[v];

      for (int h(oldH); h < highestGap + 1; ++h) {
        for (int i(gapNxt[h + maxn]); i < maxn; i = gapNxt[i]) {
          height[i] = maxn;
        }

        gapNxt[h + maxn] = gapPrv[h + maxn] = h + maxn;
      }

      highestGap = oldH - 1;
    }
  }
  inline T calc(int s, int t) {
    this->s = s;
    this->t = t;

    for (int v(0); v < maxn; ++v) {
      std::sort(edges.begin() + first_edge[v],
                edges.begin() + first_edge[v + 1],
                [](edge &l, edge &r) { return l.to < r.to; });

      for (int i(first_edge[v]); i < first_edge[v + 1]; ++i) {
        auto &e = edges[i];
        edges[e.rev].rev = i;
      }
    }

    std::copy(first_edge.begin(), first_edge.begin() + maxn, arc.begin());
    std::fill(excess.begin(), excess.begin() + maxn, 0);
    excess[s] = INF, excess[t] = -INF;
    globalRelabel();

    for (int ie(first_edge[s]); ie < first_edge[s + 1]; ++ie)
      push(s, edges[ie]);

    for (; ~highest; --highest) {
      while (~lst[highest]) {
        int v = lst[highest];
        lst[highest] = nxt[v];

        if (height[v] == highest) {
          discharge(v);

          if (work == eax) globalRelabel();
        }
      }
    }

    return excess[t] + INF;
  }
};

int main() {
  int n, m, s, t;
  std::cin >> n >> m >> s >> t;
  s--, t--;
  std::vector<std::array<int, 3>> edges(m);
  std::vector<int> degrees(n);

  for (auto &edge : edges) {
    std::cin >> edge[0] >> edge[1] >> edge[2];
    edge[0]--, edge[1]--;
    degrees[edge[0]]++;
    degrees[edge[1]]++;
  }

  HLPP<int> hlpp(degrees, n, m);
  for (auto &edge : edges) {
    hlpp.addEdge(edge[0], edge[1], edge[2]);
  }

  std::cout << hlpp.calc(s, t) << '\n';
  return 0;
}