#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      a[i].first = plantTime[i];
      a[i].second = growTime[i];
    }
    sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
      if (x.second == y.second) return x.first < y.first;
      return x.second > y.second;
    });

    int res = 0, cur_time = 0;
    for (int i = 0; i < n; i++) {
      res = max(res, cur_time + a[i].first + a[i].second);
      cur_time += a[i].first;
    }
    return res;
  }
};
int main() {
  Solution s;
  int n;
  cin >> n;
  vector<int> plantTime(n), growTime(n);
  for (int i = 0; i < n; i++) cin >> plantTime[i];
  for (int i = 0; i < n; i++) cin >> growTime[i];
  cout << s.earliestFullBloom(plantTime, growTime) << endl;
  return 0;
}