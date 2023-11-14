#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	set<int> dp[11][11];
	while (cin >> n && n) {
		cin >> m;
		int res = 0;
		vector<int> ans, v;
		while (m--) {
			cin >> k;
			v = vector<int>(k);
			for (int i = 0; i < k; ++i) cin >> v[i];
			if (v[0] != 1) {
				if (ans.empty() || ans.size() > v.size())
					ans = v;
				else if (ans.size() == v.size()) {
					bool neo = false;
					for (int i = ans.size() - 1; i >= 0; --i) {
						if (ans[i] > v[i]) {
							neo = true;
							break;
						}
						if (ans[i] < v[i]) break;
					}
					if (neo) ans = v;
				}
				continue;
			}
			for (int i = 0; i <= 10; ++i)
				for (int j = 0; j <= 10; ++j) dp[i][j].clear();
			function<set<int>(int, int)> construct
			  = [&](int remain, int idx) {
				set<int> res = {0};
				if (!dp[remain][idx].empty())
					return dp[remain][idx];
				if (remain == 0 || idx == k) return res;
				for (int select = 0; select <= remain; ++select) {
					auto child = construct(remain - select, idx + 1);
					for (auto x : child)
						res.insert(x + select * v[idx]);
				}
				dp[remain][idx] = res;
				return res;
			};
			set<int> s = construct(n, 0);
			// for(auto x : s) cout << x << " ";
			// cout << "\n";
			int reach = -1;
			for (auto x : s) {
				if (x != reach + 1) break;
				reach++;
			}
			if (reach > res) ans = v, res = reach;
			else if (reach == res) {
				if (ans.empty() || ans.size() > v.size())
					ans = v;
				else if (ans.size() == v.size()) {
					bool neo = false;
					for (int i = ans.size() - 1; i >= 0; --i) {
						if (ans[i] > v[i]) {
							neo = true;
							break;
						}
						if (ans[i] < v[i]) break;
					}
					if (neo) ans = v;
				}
			}
		}
        printf("max coverage =%4d :", res);
		for (int x : ans) printf("%3d", x);
        printf("\n");
	}
	return 0;
}
