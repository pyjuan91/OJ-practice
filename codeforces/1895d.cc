#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i < n; i++) cin >> a[i], a[i] ^= a[i - 1];
	for (int i = 25; i >= 0; i--) {
		int cnt = 0;
		for (int j = 1; j < n; j++) cnt += (a[j] >> i) & 1;
		res += (cnt * 2 > n ? 1 << i : 0);
	}
	for (int i = 0; i < n; i++) cout << (a[i] ^ res) << ' ';
	return 0;
}
