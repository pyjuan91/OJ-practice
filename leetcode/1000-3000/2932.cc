#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int maximumStrongPairXor(vector<int>& nums) {
			int res = 0, n = nums.size();
			for (int i = 0; i < n; i++) {
				for (int j = i; j < n; j++) {
					if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
						res = max(res, nums[i] ^ nums[j]);
				}
			}
			return res;
		}
};
int main() {
	Solution s;
	vector<int> nums = {2, 3, 4, 7};
	cout << s.maximumStrongPairXor(nums) << endl;
	return 0;
}