#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n, m, k, res = 0;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i) a[i] += a[i - 1];
	}
	for (int j = 0; j < m; j++) {
		cin >> b[j];
		if (j) b[j] += b[j - 1];
	}
	for (int i = 0; i < m; i++) {
		int remain = k - b[i];
		if (remain < 0) break;
		auto iter = upper_bound(a.begin(), a.end(), remain);
		res = max(res, (i + 1 + (int)(iter - a.begin())));
	}
	auto iter = upper_bound(a.begin(), a.end(), k);
	res = max(res, (int)(iter - a.begin()));
	cout << res;
	return 0;
}