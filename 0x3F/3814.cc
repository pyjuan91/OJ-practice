#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

class Solution {
 public:
  int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
    int n = costs.size();
    map<int, vector<int>> machines;
    for (int i = 0; i < n; i++) {
      machines[costs[i]].push_back(capacity[i]);
    }
    int res = 0;
    for (auto iter = machines.begin(); iter != machines.end(); iter++) {
      auto& v = iter->second;
      sort(v.rbegin(), v.rend());
      while (v.size() > 2) v.pop_back();
      while (v.size() < 2) v.push_back(0);
    }

    int p_first = 0, p_second = 0;
    for (auto& [k, v] : machines) {
    //   debug(k);
    //   debug(v);
    //   debug(res);
    //   debug(machines);
      auto update = [&]() -> void {
        array<int, 4> arr = {p_first, p_second, v[0], v[1]};
        sort(arr.rbegin(), arr.rend());
        v[0] = p_first = arr[0], v[1] = p_second = arr[1];
      };
      if (k >= budget) break;
      res = max(res, v.front());
      if (budget - k > k) {
        update();
        res = max(res, v[0] + v[1]);
        continue;
      }
      auto iter = machines.lower_bound(budget - k);
      if (iter == machines.begin()) {
        update();
        continue;
      }
      iter = prev(iter);
      if (iter->first != k) {
        res = max(res, v[0] + iter->second[0]);
        update();
      } else {
        update();
        res = max(res, v[0] + v[1]);
      }
    }
    return res;
  }
};

int main() {
  vector<int> costs = {1, 7, 3};
  vector<int> capacity = {7, 3, 5};
  int budget = 13;
  //   cout << budget << "\n";
  auto s = Solution();
  cout << s.maxCapacity(costs, capacity, budget);

  return 0;
}