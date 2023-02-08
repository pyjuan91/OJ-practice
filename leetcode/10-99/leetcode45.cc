#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int jump(vector<int>& nums) {
			vector<int> dp(nums.size(), 1e5);
			dp[0] = 0;
			for (int i = 0; i < nums.size(); i++) {
				for (int j = i + 1;
						 j < nums.size() && j <= i + nums[i]; j++) {
					dp[j] = min(dp[j], dp[i] + 1);
				}
			}
			return dp[nums.size() - 1];
		}
};
int main() { return 0; }