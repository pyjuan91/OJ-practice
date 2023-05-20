#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, d, aoki = 0, snuke = 0;
	cin >> n >> m >> d;
	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	for (;;) {
		if (llabs(a[aoki] - b[snuke]) <= d) break;
		if (a[aoki] > b[snuke]) {
			if (aoki + 1 >= n) break;
			aoki += 1;
		}
		else {
			if (snuke + 1 >= m) break;
			snuke += 1;
		}
	}
	if (llabs(a[aoki] - b[snuke]) <= d)
		cout << a[aoki] + b[snuke] << "\n";
	else cout << "-1\n";
	return 0;
}