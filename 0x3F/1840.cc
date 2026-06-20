#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    vector<pair<int, int>> r;
    for (const auto& restriction : restrictions) {
      r.push_back(make_pair(restriction[0], restriction[1]));
    }
    r.push_back(make_pair(1, 0));
    sort(r.begin(), r.end());
    if (r.back().first != n) r.push_back(make_pair(n, n - 1));

    for (int i = 1; i < r.size(); i++) {
      r[i].second =
          min(r[i].second, r[i - 1].second + r[i].first - r[i - 1].first);
    }

    for (int i = r.size() - 2; i >= 0; i--) {
      r[i].second =
          min(r[i].second, r[i + 1].second + r[i + 1].first - r[i].first);
    }

    int res = 0;
    for (int i = 1; i < r.size(); i++) {
      int hi = max(r[i].second, r[i - 1].second);
      int lo = min(r[i].second, r[i - 1].second);
      int gap = hi - lo;
      int quota = r[i].first - r[i - 1].first - 1;
      quota -= gap;
      res = max(res, hi + (quota + 1) / 2);
    }
    return res;
  }
};

int main() { return 0; }