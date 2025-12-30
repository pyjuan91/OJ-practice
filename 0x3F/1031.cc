#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& nums, int fl, int sl) {
    int n = nums.size();
    vector<int> prefix(n);
    for (int i = 0; i < n; i++) {
      prefix[i] = (i ? prefix[i - 1] : 0) + nums[i];
    }

    auto patty = [&](int firstLen, int secondLen) -> int {
      int res = 0;
      for (int i = 0; i <= n - firstLen; i++) {
        int first_sum = prefix[i + firstLen - 1] - (i ? prefix[i - 1] : 0);

        for (int j = i + firstLen; j <= n - secondLen; j++) {
          int second_sum = prefix[j + secondLen - 1] - (j ? prefix[j - 1] : 0);
          res = max(res, first_sum + second_sum);
        }
      }

      return res;
    };

    return max(patty(fl, sl), patty(sl, fl));
  }
};

int main() { return 0; }