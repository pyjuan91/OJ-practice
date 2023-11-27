#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		const long long mod = 1e9 + 7;
		vector<vector<int>> valid;
		vector<vector<long long>> dp;
		void init() {
			valid.resize(10);
			valid[0] = {4, 6};
			valid[1] = {6, 8};
			valid[2] = {7, 9};
			valid[3] = {4, 8};
			valid[4] = {0, 3, 9};
			valid[5] = {};
			valid[6] = {0, 1, 7};
			valid[7] = {2, 6};
			valid[8] = {1, 3};
			valid[9] = {2, 4};
			dp = vector<vector<long long>>(
			  10, vector<long long>(5001, -1ll));
		}
		int knightDialer(int n) {
			init();
			long long res = 0;
			for (int i = 0; i < 10; i++)
				res = (res + chaewon(i, n - 1)) % mod;
			return res;
		}
		long long chaewon(int num, int step) {
			if (step == 0) return 1ll;
			if (step == 1) return 1ll * valid[num].size();
			if (dp[num][step] != -1) return dp[num][step];
			long long res = 0ll;
			for (auto x : valid[num])
				res = (res + chaewon(x, step - 1)) % mod;
			return dp[num][step] = res;
		}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	cout << s.knightDialer(n) << endl;
	return 0;
}