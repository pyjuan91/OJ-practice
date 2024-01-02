#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<vector<int>> findMatrix(vector<int>& nums) {
			vector<vector<int>> res;
			vector<int> cnt(201, 0);
			for (auto& x : nums) cnt[x]++;
			for (int i = 0; i <= 200; i++) {
				if (cnt[i] == 0) continue;
				int mn = min(cnt[i], (int) res.size());
				int mx = max(cnt[i], (int) res.size());
				for (int j = 0; j < mn; j++)
					res[j].push_back(i);
				if (cnt[i] == mn) continue;
				for (int j = mn; j < mx; j++)
					res.push_back({i});
			}
			return res;
		};
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	vector<vector<int>> ans = s.findMatrix(nums);
	for (auto& x : ans) {
		for (auto& y : x) cout << y << " ";
		cout << endl;
	}
	return 0;
}