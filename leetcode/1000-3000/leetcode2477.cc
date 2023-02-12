#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> route;
  vector<vector<int>> info;
  long long ans = 0;
  int go(int cur, int prev, int seats) {
    int res = 0;
    for (auto e : route[cur]) {
      if (e == prev) continue;
      res += go(e, cur, seats);
    }
    res += 1;
    if (cur != 0) ans += 1LL * res / seats + 1LL * (res % seats != 0);
    return res;
  }
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    long long res = 0LL;
    route.resize(1e5 + 5);
    info.resize(1e5 + 5);
    for (auto edge : roads) {
      route[edge[0]].emplace_back(edge[1]);
      route[edge[1]].emplace_back(edge[0]);
    }
    go(0, -1, seats);
    return ans;
  }
};

int main() {
  vector<vector<int>> roads = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
  int seats = 5;
  Solution s;
  cout << s.minimumFuelCost(roads, seats) << endl;
  return 0;
};