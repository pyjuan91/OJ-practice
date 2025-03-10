#include <bits/stdc++.h>
#include "debug.cc"
using namespace std;

class Solution {
private:
  bool isRectangle(array<pair<int, int>, 4>& p) {
    return (p[0].first == p[1].first and p[1].second == p[3].second and p[3].first == p[2].first and p[2].second == p[0].second);
  }
  bool isThereAnyInside(vector<vector<int>>& points, array<pair<int, int>, 4>& p, array<int, 4>& idx) {
    for (int i = 0; i < points.size(); i++) {
      if (i == idx[0] or i == idx[1] or i == idx[2] or i == idx[3]) continue;
      if (p[0].first <= points[i][0] and points[i][0] <= p[2].first and p[0].second <= points[i][1] and points[i][1] <= p[1].second) {
        return true;
      }
    }
    return false;
  }
public:
  int maxRectangleArea(vector<vector<int>>& points) {
    size_t n = points.size();
    if (n < 4) return 0;
    int max_area = -1;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          for (int l = k + 1; l < n; l++) {
            array<pair<int, int>, 4> p;
            p[0] = { points[i][0], points[i][1] };
            p[1] = { points[j][0], points[j][1] };
            p[2] = { points[k][0], points[k][1] };
            p[3] = { points[l][0], points[l][1] };
            sort(p.begin(), p.end());
            array<int, 4> idx = { i, j, k, l };
            if (isRectangle(p) and not isThereAnyInside(points, p, idx)) {
              int area = (p[2].first - p[0].first) * (p[1].second - p[0].second);
              max_area = max(max_area, area);
            }
          }
        }
      }
    }
    return max_area;
  }
};

int main() {
  int n;
  cin >> n;
  vector<vector<int>> points(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    cin >> points[i][0] >> points[i][1];
  }
  Solution sol;
  cout << sol.maxRectangleArea(points) << endl;
  return 0;
}