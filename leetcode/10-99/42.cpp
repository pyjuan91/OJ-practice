#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left_max_height(n), right_max_height(n);
    for (int i = 1; i < n; i++)
      left_max_height[i] = max(left_max_height[i - 1], height[i - 1]);
    for (int i = n - 2; i >= 0; i--)
      right_max_height[i] = max(right_max_height[i + 1], height[i + 1]);
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
      int min_height = min(left_max_height[i], right_max_height[i]);
      if (min_height > height[i]) res += min_height - height[i];
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(height) << endl;
  return 0;
}