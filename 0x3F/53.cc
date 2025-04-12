#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int res = INT32_MIN, sum = 0;
    for (const auto& num : nums) {
      sum += num;
      res = max(res, sum);
      if (sum < 0) sum = 0;
    }
    return res;
  }
};

int main() {
  return 0;
}