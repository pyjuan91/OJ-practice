#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int64_t minCost(vector<int32_t>& arr, vector<int32_t>& brr, int64_t k) {
    int64_t cost_without_rearrangement = 0;
    for (int i = 0; i < arr.size(); i++) {
      cost_without_rearrangement += llabs(arr[i] - brr[i]);
    }
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    int64_t cost_with_rearrangement = k;
    for (int i = 0; i < arr.size(); i++) {
      cost_with_rearrangement += llabs(arr[i] - brr[i]);
    }
    return min(cost_without_rearrangement, cost_with_rearrangement);
  }
};

int main() {
  Solution s;
  return 0;
}