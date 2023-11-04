#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int sumCounts(vector<int>& nums) {
			int res = 0, n = nums.size();
			for (int len = 1; len <= n; len++) {
				int cnt[101] = {}, dis = 0;
				for (int i = 0; i < len; i++) {
					cnt[nums[i]]++;
					if (cnt[nums[i]] == 1) dis++;
				}
				res += dis * dis;
				for (int i = len; i < n; i++) {
					cnt[nums[i - len]]--;
					if (cnt[nums[i - len]] == 0) dis--;
					cnt[nums[i]]++;
					if (cnt[nums[i]] == 1) dis++;
					res += dis * dis;
				}
			}
			return res;
		}
};
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	Solution s;
	cout << s.sumCounts(nums) << endl;
	return 0;
}