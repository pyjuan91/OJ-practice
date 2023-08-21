#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<int, int> a[200005];
map<int, int> x, y, diff, su;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i].first >> a[i].second;
		sort(a, a + n);
		x.clear(), y.clear(), diff.clear(), su.clear();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += x[a[i].first];
			ans += y[a[i].second];
			ans += diff[a[i].first - a[i].second];
			ans += su[a[i].first + a[i].second];
			x[a[i].first]++;
			y[a[i].second]++;
			diff[a[i].first - a[i].second]++;
			su[a[i].first + a[i].second]++;
		}
		cout << ans * 2ll << '\n';
	}
	return 0;
}
