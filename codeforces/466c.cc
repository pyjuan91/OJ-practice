#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	vector<int> a(n + 1), prefix(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		prefix[i] = a[i] + prefix[i - 1];
	}
	map<int, int> m;
	m[prefix[1]] += 1;
	for (int i = 2; i < n; i++) {
		int tar = prefix[n] - prefix[i];
		if (prefix[i] != tar * 2) {
			m[prefix[i]] += 1;
			continue;
		}
		if (m.count(tar)) res += m[tar];
		m[prefix[i]] += 1;
	}
	cout << res << "\n";
	return 0;
}
