#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> leftRightDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> left_sum(n), right_sum(n);
    for (int i = 1; i < n; i++) left_sum[i] = left_sum[i - 1] + nums[i - 1];
    for (int i = n - 2; i >= 0; i--)
      right_sum[i] = right_sum[i + 1] + nums[i + 1];

    for (int i = 0; i < n; i++) left_sum[i] = abs(left_sum[i] - right_sum[i]);
    return left_sum;
  }
};
int main() { return 0; }