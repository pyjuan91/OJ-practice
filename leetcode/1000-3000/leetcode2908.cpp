#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int minimumSum(vector<int>& nums) {
			const int n = nums.size();
			vector<int> pref_min(n), suff_min(n);
			pref_min[0] = nums[0], suff_min[n - 1] = nums[n - 1];
			for (int i = 1; i < n; i++)
				pref_min[i] = min(pref_min[i - 1], nums[i]);
			for (int i = n - 2; i >= 0; i--)
				suff_min[i] = min(suff_min[i + 1], nums[i]);
			int res = INT32_MAX;
			for (int i = 1; i < n - 1; i++) {
				if (nums[i] > pref_min[i - 1] && nums[i] > suff_min[i + 1])
					res = min(
					  res, pref_min[i - 1] + nums[i] + suff_min[i + 1]);
			}
			return res == INT32_MAX ? -1 : res;
		}
};
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	Solution s;
	cout << s.minimumSum(nums) << endl;
	return 0;
}