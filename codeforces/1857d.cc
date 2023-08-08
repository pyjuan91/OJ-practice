#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		vector<pair<int, int>> diff;
		for (int i = 1; i <= n; i++) {
			diff.push_back({a[i] - b[i], i});
		}
		sort(diff.begin(), diff.end());
		vector<int> ans;
		int v = diff.back().first;
		while (!diff.empty() && diff.back().first == v)
			ans.push_back(diff.back().second), diff.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto& x : ans) cout << x << ' ';
        cout << '\n';
	}
	return 0;
}
