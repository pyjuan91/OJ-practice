#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int res = 0;
    int n = points.size();
    vector<vector<int>> dist(n, vector<int>(n, 0));
    auto get_dist = [&](int i, int j) -> int {
      int x1 = points[i][0], y1 = points[i][1];
      int x2 = points[j][0], y2 = points[j][1];
      return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> dist_cnt;
      for (int j = 0; j < n; j++) {
        dist_cnt[get_dist(i, j)]++;
      }
      for (const auto& [k, v] : dist_cnt) {
        res += v * (v - 1);
      }
    }
    return res;
  }
};

int main() { return 0; }