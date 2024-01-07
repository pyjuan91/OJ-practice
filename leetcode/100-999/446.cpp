#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int numberOfArithmeticSlices(vector<int>& nums) {
			const int n = nums.size();
			vector<unordered_map<int, int>> dp(n);
			int res = 0;
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < i; j++) {
					int64_t diff
					  = static_cast<int64_t>(nums[i]) - nums[j];
					if (diff > INT32_MAX || diff < INT32_MIN)
						continue;
					dp[i][diff]++;
					if (dp[j].count(diff)) {
						dp[i][diff] += dp[j][diff];
						res += dp[j][diff];
					}
				}
			}
			return res;
		}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << s.numberOfArithmeticSlices(nums) << endl;
	return 0;
}