#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    auto cmp = [&](const pair<int, int>& lhs,
                   const pair<int, int>& rhs) -> bool {
      int sum1 = nums1[lhs.first] + nums2[lhs.second];
      int sum2 = nums1[rhs.first] + nums2[rhs.second];
      return sum1 > sum2;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    pq.push(make_pair(0, 0));
    set<pair<int, int>> in_que;
    in_que.insert(make_pair(0, 0));
    vector<vector<int>> res;
    while (res.size() < k) {
      auto cur_idx_pair = pq.top();
      pq.pop();
      res.push_back({nums1[cur_idx_pair.first], nums2[cur_idx_pair.second]});
      if (cur_idx_pair.first + 1 < nums1.size() and
          !in_que.count(
              make_pair(cur_idx_pair.first + 1, cur_idx_pair.second))) {
        pq.push(make_pair(cur_idx_pair.first + 1, cur_idx_pair.second));
        in_que.insert(make_pair(cur_idx_pair.first + 1, cur_idx_pair.second));
      }
      if (cur_idx_pair.second + 1 < nums2.size() and
          !in_que.count(
              make_pair(cur_idx_pair.first, cur_idx_pair.second + 1))) {
        pq.push(make_pair(cur_idx_pair.first, cur_idx_pair.second + 1));
        in_que.insert(make_pair(cur_idx_pair.first, cur_idx_pair.second + 1));
      }
    }
    return res;
  }
};

int main() { return 0; }