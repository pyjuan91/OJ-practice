#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int minGroupsForValidAssignment(vector<int>& nums) {
			map<int, int> mp;
			for (auto x : nums) mp[x]++;
			vector<int> v;
			for (auto p : mp) v.push_back(p.second);
			int ma = *min_element(v.begin(), v.end());
			for (int div = 1; div <= ma; div++) {
				int tar = ma / div;
				if (ma % div > tar) continue;
				// only allow tar and tar + 1
				auto chaewon = [&](int x) {
					int su = 0;
					for (auto p : v) {
						int y = p / x;
						if (p % x == 0) su += y;
						else if (p % x == x - 1) su += y + 1;
						else if (x - 1 - (p % x) <= y)
							su += y + 1;
						else return -1;
					}
					return su;
				};
				int res = chaewon(tar + 1);
				if (res != -1) return res;
				if (ma % div == 0) {
					// allow tar and tar - 1
					res = chaewon(tar);
					if (res != -1) return res;
				}
			}
			return nums.size();
		}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];
	cout << s.minGroupsForValidAssignment(nums) << endl;
	return 0;
}