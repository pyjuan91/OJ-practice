#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int lengthOfLIS(vector<int>& nums) {
			int n = nums.size(), res = 0;

			const int mx = 2e4 + 1;
			vector<int> seg(2 * mx, 0);
			auto update = [&](int p, int v) {
				for (seg[p += mx] = v; p > 1; p >>= 1)
					seg[p >> 1] = max(seg[p], seg[p ^ 1]);
			};
			auto query = [&](int l, int r) {
				int res = 0;
				for (l += mx, r += mx; l < r; l >>= 1, r >>= 1) {
					if (l & 1) res = max(res, seg[l++]);
					if (r & 1) res = max(res, seg[--r]);
				}
				return res;
			};

			for (int i = 0; i < n; i++) {
                nums[i] += 1e4;
				int v = query(0, nums[i]) + 1;
				res = max(res, v);
				update(nums[i], v);
			}

			return res;
		}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];
	cout << s.lengthOfLIS(nums) << endl;
	return 0;
}