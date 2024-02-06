#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ifstream cin("convention2.in");
  ofstream cout("convention2.out");
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a, e;
  struct Cow {
    int arrival, eating, seniority;
    Cow(int a, int e, int s) : arrival(a), eating(e), seniority(s) {}
    bool operator<(const Cow &c) const { return seniority < c.seniority; }
  };

  cin >> n;
  vector<Cow> cows;
  for (int i = n; i >= 1; i--) {
    cin >> a >> e;
    cows.emplace_back(a, e, i);
  }

  sort(cows.rbegin(), cows.rend(), [](const Cow &a, const Cow &b) {
    if (a.arrival == b.arrival) return a.seniority > b.seniority;
    return a.arrival < b.arrival;
  });

  priority_queue<Cow> pq;
  pq.push(cows.back());
  cows.pop_back();

  int res = 0, cur_time = pq.top().arrival;

  while (!pq.empty()) {
    auto cur_cow = pq.top();
    pq.pop();
    res = max(res, cur_time - cur_cow.arrival);
    cur_time += cur_cow.eating;

    while (!cows.empty() && cows.back().arrival <= cur_time) {
      pq.push(cows.back());
      cows.pop_back();
    }
    if (pq.empty() && !cows.empty()) {
      pq.push(cows.back());
      cows.pop_back();
      cur_time = pq.top().arrival;
    }
  }

  cout << res << '\n';

  return 0;
}
