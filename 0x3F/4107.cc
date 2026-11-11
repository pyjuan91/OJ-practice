#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int countSuffix(vector<int>& nums, vector<int>& target) {
    vector<bool> is_head_same;
    for (int i = 0; i < nums.size(); i++) {
      is_head_same.push_back(nums[i] == target[i] and
                             (is_head_same.empty() or is_head_same.back()));
    }
    unordered_map<int, int> diff;
    auto incre = [&](int index, int sign) -> void {
      diff[index] += sign;
      if (diff[index] == 0) {
        diff.erase(index);
      }
    };
    int res = 0;
    bool is_tail_non_insc = true;
    for (int i = nums.size() - 1; i >= 0; i--) {
      incre(nums[i], 1);
      incre(target[i], -1);
      if (i + 1 < nums.size() and target[i] < target[i + 1]) {
        is_tail_non_insc = false;
      }
      if (diff.empty() and is_tail_non_insc and (i == 0 or is_head_same[i - 1]))
        res++;
    }
    return res;
  }
};

int main() { return 0; }