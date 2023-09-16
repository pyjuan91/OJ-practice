#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		vector<int> res;
		for (int i = 1; i < n; i++)
			if (a[i] != a[i - 1]) res.push_back(i);
		if (a[n - 1] != b[n - 1]) res.push_back(n);
		for (int i = n - 1; i > 0; i--)
			if (b[i - 1] != b[i]) res.push_back(i);
		cout << res.size() << ' ';
		for (int i : res) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}
