#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimizeSum(vector<int>& nums) {
    vector<int> left(3, INT32_MAX);
    vector<int> right(3, 0);
    for (const auto& num : nums) {
      if (num < left[0]) {
        left[2] = left[1];
        left[1] = left[0];
        left[0] = num;
      } else if (num < left[1]) {
        left[2] = left[1];
        left[1] = num;
      } else if (num < left[2]) {
        left[2] = num;
      }

      if (num > right[2]) {
        right[0] = right[1];
        right[1] = right[2];
        right[2] = num;
      } else if (num > right[1]) {
        right[0] = right[1];
        right[1] = num;
      } else if (num > right[0]) {
        right[0] = num;
      }
    }

    int res = INT32_MAX;
    for (int i = 0; i < 3; i++) res = min(res, right[i] - left[i]);
    return res;
  }
};

int main() { return 0; }