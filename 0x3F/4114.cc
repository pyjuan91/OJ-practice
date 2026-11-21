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
  long long countConsistent(vector<int>& nums) {
    const int n = nums.size();
    long long res = 0;
    unordered_map<int, int> last_pos;
    vector<tuple<int, int, int>> segments;

    for (int r = 0; r < n; r++) {
      last_pos[nums[r]] = r;
      segments.push_back(make_tuple(r, r, nums[r]));
      for (int l = segments.size() - 2; l >= 0; l--) {
        std::get<2>(segments[l]) &= nums[r];
      }
      debug(r);
      debug(segments);
      debug(last_pos);
      vector<tuple<int, int, int>> next_segments;
      for (int i = 0; i < segments.size(); i++) {
        if (next_segments.empty() or
            std::get<2>(next_segments.back()) != std::get<2>(segments[i])) {
          next_segments.push_back(segments[i]);
        } else {
          std::get<1>(next_segments.back()) = std::get<1>(segments[i]);
        }
      }
      debug(next_segments);
      swap(segments, next_segments);

      for (const auto& [l, r, v] : segments) {
        if (last_pos.count(v) and last_pos[v] >= l) {
          res += min(r, last_pos[v]) - l + 1;
        }
      }
      debug(res);
    }

    return res;
  }
};

int main() {
  vector<int> nums = {1, 8, 5, 9};
  Solution s;
  cout << s.countConsistent(nums) << endl;
  return 0;
}