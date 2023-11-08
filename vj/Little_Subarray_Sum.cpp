#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, l, r, x, su = 0;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i >= l && i <= r) su += x;
	}
    cout << su << '\n';
	return 0;
}
