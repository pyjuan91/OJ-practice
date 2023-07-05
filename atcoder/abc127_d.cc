#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, res = 0;
	cin >> n >> m;
	map<int, int> mp;
	for (int i = 0; i < n; i++) cin >> a, mp[a] += 1;
	for (int i = 0; i < m; i++) cin >> a >> b, mp[b] += a;
	auto iter = mp.rbegin();
	while (n) {
		if (n >= iter->second) {
			res += iter->first * iter->second;
			n -= iter->second;
			iter++;
		}
		else {
			res += iter->first * n;
			n = 0;
		}
	}
	cout << res;
	return 0;
}