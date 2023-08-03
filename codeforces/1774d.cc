#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, m, sum, su[maxn], a[(size_t) 1e6 + 5], x;
void in(int i, int j) { cin >> a[m * i + j]; }
int get(int i, int j) { return a[m * i + j]; }
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(su, 0, sizeof(su));
		sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in(i, j);
				su[i] += get(i, j);
			}
			sum += su[i];
		}
		if (sum % n != 0) {
			cout << -1 << '\n';
			continue;
		}
		sum /= n;
		vector<int> extra, miss;
		vector<vector<int>> ans;
		for (int j = 0; j < m; j++) {
			extra.clear();
			miss.clear();
			for (int i = 0; i < n; i++) {
				if (get(i, j) && su[i] > sum)
					extra.push_back(i);
				if (!get(i, j) && su[i] < sum)
					miss.push_back(i);
			}
			for (size_t i = 0;
				 i < (size_t) min(extra.size(), miss.size());
				 i++) {
				su[extra[i]]--, su[miss[i]]++;
				ans.emplace_back(vector<int> {extra[i], miss[i], j});
			}
		}
		for (int i = 0; i < n; i++) {
			if (su[i] != sum) {
				cout << -1 << '\n';
				goto end;
			}
		}
		cout << ans.size() << '\n';
		for (auto &v : ans) {
			for (auto &x : v) cout << x + 1 << ' ';
			cout << '\n';
		}
	end:;
	}
	return 0;
}