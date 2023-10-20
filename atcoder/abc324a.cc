#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, x2;
	bool ok = true;
	cin >> n >> x;
	for (int i = 1; i < n; i++) {
		cin >> x2;
		if (x2 != x) ok = false;
	}
	cout << (ok ? "Yes" : "No");
	return 0;
}
