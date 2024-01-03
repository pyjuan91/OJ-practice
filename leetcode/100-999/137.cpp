#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int singleNumber(vector<int>& nums) {
			vector<int> cnt(32, 0);
			for (const auto& num : nums) {
				long long x = 1LL * num + (1LL << 31);
				for (int i = 0; i < 32; i++) {
					if (x & (1LL << i)) cnt[i]++;
				}
			}
			long long ans = 0;
			for (int i = 0; i < 32; i++) {
				if (cnt[i] % 3 == 1) ans += 1LL << i;
			}
			ans -= 1LL << 31;
			return (int) ans;
		}
};
int main() {
	Solution sol;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) { cin >> nums[i]; }
	cout << sol.singleNumber(nums) << endl;
	return 0;
}