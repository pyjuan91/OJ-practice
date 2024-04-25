#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](int a, int b) {
      string s1 = to_string(a) + to_string(b);
      string s2 = to_string(b) + to_string(a);
      return s1 > s2;
    });
    string ans;
    for (int num : nums) {
      ans += to_string(num);
    }
    return ans[0] == '0' ? "0" : ans;
  }
};
int main() {
  vector<int> nums = {3, 30, 34, 5, 9};
  Solution sol;
  cout << sol.largestNumber(nums) << endl;
}