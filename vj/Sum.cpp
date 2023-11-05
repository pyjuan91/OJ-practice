#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	if (n >= 1) {
		for (int i = 1; i <= n; i++) res += i;
	}
	else {
		for (int i = 1; i >= n; i--) res += i;
	}
    cout << res << '\n';
	return 0;
}
