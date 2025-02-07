#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxSubarraySum(vector<int>& nums) {
    unordered_map<int, long long> pre_min_when_deleting;
    long long sum = 0;
    long long max_sum = INT64_MIN;
    long long pre_min = 0;
    pre_min_when_deleting[0] = 0;

    for (const auto& num : nums) {
      sum += num;
      max_sum = max(max_sum, sum - pre_min);

      if (num < 0) {
        if (pre_min_when_deleting.count(num)) {
          pre_min_when_deleting[num] = min(pre_min_when_deleting[num], pre_min_when_deleting[0]) + num;
        }
        else {
          pre_min_when_deleting[num] = pre_min_when_deleting[0] + num;
        }
        pre_min = min(pre_min, pre_min_when_deleting[num]);
      }

      pre_min_when_deleting[0] = min(pre_min_when_deleting[0], sum);
      pre_min = min(pre_min, pre_min_when_deleting[0]);
    }

    return max_sum;
  }
};

int main() {
  return 0;
}