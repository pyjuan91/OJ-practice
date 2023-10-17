#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<vector<int>>
		  constructProductMatrix(vector<vector<int>>& grid) {
            using ll = long long;
			const ll mod = 12345;
			int n = grid.size(), m = grid[0].size();
			vector<vector<int>> ans(n, vector<int>(m, 0));
			vector<ll> prefix_row_pro(n, 1), suffix_row_pro(n, 1);
			for (int i = 0; i < n - 1; i++) {
				ll cur_row_pro = 1ll;
				for (int j = 0; j < m; j++)
					cur_row_pro = cur_row_pro * grid[i][j] % mod;
				prefix_row_pro[i + 1]
				  = prefix_row_pro[i] * cur_row_pro % mod;
			}
			for (int i = n - 1; i > 0; i--) {
				ll cur_row_pro = 1;
				for (int j = 0; j < m; j++)
					cur_row_pro = cur_row_pro * grid[i][j] % mod;
				suffix_row_pro[i - 1]
				  = suffix_row_pro[i] * cur_row_pro % mod;
			}
			for (int i = 0; i < n; i++) {
				vector<ll> pref(m, 1), suff(m, 1);
				for (int j = 0; j < m - 1; j++) {
					pref[j + 1] = pref[j] * grid[i][j] % mod;
				}
				for (int j = m - 1; j > 0; j--) {
					suff[j - 1] = suff[j] * grid[i][j] % mod;
				}
				for (int j = 0; j < m; j++)
					ans[i][j] = pref[j] * suff[j] % mod
							  * prefix_row_pro[i] % mod
							  * suffix_row_pro[i] % mod;
			}
			return ans;
		}
};
int main() { return 0; }