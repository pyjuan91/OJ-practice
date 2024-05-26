#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> cnt1(1e6 + 1, 0);
    int max_value = INT32_MIN;
    for (int num : nums1)
      if (num % k == 0) {
        cnt1[num / k]++;
        max_value = max(max_value, num / k);
      }
    unordered_map<int, int> cnt2;
    for (int num : nums2) cnt2[num]++;
    int64_t res = 0;
    for (auto [num, cnt] : cnt2) {
      int64_t temp = 0;
      for (int i = num; i <= max_value; i += num) temp += cnt1[i];
      res += temp * cnt;
    }
    return res;
  }
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> nums1(n), nums2(m);
  for (int i = 0; i < n; i++) cin >> nums1[i];
  for (int i = 0; i < m; i++) cin >> nums2[i];
  Solution obj;
  cout << obj.numberOfPairs(nums1, nums2, k) << endl;
}