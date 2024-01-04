#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int minOperations(vector<int>& nums) {
			unordered_map<int, int> cnt;
			for (auto x : nums) cnt[x]++;
			int res = 0;
			for (auto [x, y] : cnt) {
				if (y == 1) return -1;
				res += y / 3 + (y % 3 != 0);
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
	cout << s.minOperations(nums) << endl;
	return 0;
}