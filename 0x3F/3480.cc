#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
    vector<int> b_min_1(n + 2, n + 1);
    vector<int> b_min_2(n + 2, n + 1);

    for (const auto& conflicting_pair : conflictingPairs) {
      int a = min(conflicting_pair[0], conflicting_pair[1]);
      int b = max(conflicting_pair[0], conflicting_pair[1]);
      if (b_min_1[a] > b) {
        b_min_2[a] = b_min_1[a];
        b_min_1[a] = b;
      } else {
        b_min_2[a] = min(b_min_2[a], b);
      }
    }

    long long tot = 0;
    int ib1 = n;
    int b2 = INT32_MAX;
    vector<long long> del_count(n + 1, 0);

    for (int i = n; i >= 1; i--) {
      if (b_min_1[ib1] > b_min_1[i]) {
        b2 = b_min_1[ib1];
        ib1 = i;
      } else {
        b2 = min(b2, b_min_1[i]);
      }

      tot += min(b_min_1[ib1], n + 1) - i;
      del_count[ib1] +=
          min({b2, b_min_2[ib1], n + 1}) - min(b_min_1[ib1], n + 1);
    }

    return tot + *max_element(del_count.begin(), del_count.end());
  }
};

int main() { return 0; }