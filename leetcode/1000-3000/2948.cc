#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

class Solution {
public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    set<pair<int, int>> nodes;
    for (int i = 0; i < n; i++) {
      nodes.insert({ nums[i], i });
    }
    auto dsu = atcoder::dsu(n);
    for (auto it = ++(nodes.begin()), prv = nodes.begin(); it != nodes.end(); it++) {
      if (it->first - prv->first <= limit) {
        dsu.merge(prv->second, it->second);
      }
      prv = it;
    }
    auto groups = dsu.groups();
    for (auto& group : groups) {
      vector<int> arr;
      for (auto& x : group) {
        arr.push_back(nums[x]);
      }
      sort(arr.begin(), arr.end());
      for (int i = 0; i < group.size(); i++) {
        nums[group[i]] = arr[i];
      }
    }
    return nums;
  }
};

int main() {
  int n, limit;
  cin >> n >> limit;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  Solution sol;
  auto ans = sol.lexicographicallySmallestArray(nums, limit);
  for (auto& x : ans) cout << x << " ";
  return 0;
}