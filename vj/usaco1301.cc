#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, res = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (int &i : a) cin >> i;
	res = k + 1;
	for (int i = 1; i < n; i++) {
		res += min(a[i] - a[i - 1], k + 1);
	}
    cout << res << '\n';
	return 0;
}
