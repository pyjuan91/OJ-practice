#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = INT64_MIN, rv = 0;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		if (res < a[i] * (n - i))
			res = a[i] * (n - i), rv = a[i];
	cout << res << ' ' << rv << '\n';
	return 0;
}
