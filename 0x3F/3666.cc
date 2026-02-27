#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minOperations(string s, int k) {
    const int n = s.size();
    int m = 0;
    for (const auto& c : s) m += (c == '0');

    vector<int> dist(n + 1, INT32_MAX);
    dist[m] = 0;
    vector<set<int>> candidates(2);
    for (int i = 0; i <= n; i += 2) {
      if (i != m) candidates[0].insert(i);
    }
    for (int i = 1; i <= n; i += 2) {
      if (i != m) candidates[1].insert(i);
    }

    queue<int> q;
    q.push(m);
    while (!q.empty()) {
      int cur_zeros = q.front();
      q.pop();
      int c_min = max(0, cur_zeros - n + k);
      int c_max = min(cur_zeros, k);
      int nxt_zeros_min = (cur_zeros + k - 2 * c_max);
      int nxt_zeros_max = (cur_zeros + k - 2 * c_min);
      auto& candidate = candidates[nxt_zeros_min & 1];
      for (auto iter = candidate.lower_bound(nxt_zeros_min);
           iter != candidate.end() && *iter <= nxt_zeros_max;) {
        q.push(*iter);
        dist[*iter] = dist[cur_zeros] + 1;
        iter = candidate.erase(iter);
      }
    }

    return dist[0] == INT32_MAX ? -1 : dist[0];
  }
};

int main() {
  auto s = new Solution();
  cout << s->minOperations("001", 3) << "\n";
  return 0;
}