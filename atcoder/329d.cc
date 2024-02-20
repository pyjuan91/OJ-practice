#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x;
  cin >> n >> m;
  struct Candidate {
    int id, votes;
    Candidate(int id, int votes) : id(id), votes(votes) {}
    Candidate() {}
    bool operator>(const Candidate &c) const {
      if (votes != c.votes) return votes > c.votes;
      return id < c.id;
    }
  };
  vector<Candidate> seg(4 * n + 200);
  function<void(int, int, int, int, int)> update =
      [&](int v, int tl, int tr, int pos, int val) -> void {
    if (tl == tr) {
      seg[v].id = pos;
      seg[v].votes++;
      return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, val);
    else
      update(2 * v + 1, tm + 1, tr, pos, val);
    seg[v] = (seg[v * 2] > seg[2 * v + 1] ? seg[v * 2] : seg[v * 2 + 1]);
  };
  while (m--) {
    cin >> x;
    update(1, 1, n, x, 1);
    cout << seg[1].id << '\n';
  }
  return 0;
}
