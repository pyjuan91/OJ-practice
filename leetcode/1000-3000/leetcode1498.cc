#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int mod_power(int shift, int mod) {
			int res = 1, base = 2;
			while (shift) {
				if (shift & 1) res = (res * base) % mod;
				base = (1LL* base * base) % mod;
				shift >>= 1;
			}
			return res;
		}
		int numSubseq(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int left = 0, right = nums.size() - 1, res = 0;
			const int mod = 1e9 + 7;

			while (left <= right) {
				while (left < right && nums[left] + nums[right] > target)
					right -= 1;
				if (nums[left] + nums[right] <= target)
					res = (res + mod_power(right - left, mod)) % mod;
				left += 1;
			}
			return res;
		}
};
int main() {
	auto s = Solution();
	vector<int> nums = {3, 3, 6, 8};
	cout << s.numSubseq(nums, 10) << endl;
	return 0;
}