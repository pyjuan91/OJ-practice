#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = floor(n * 1.0 / 1.08);
	if (floor(ans * 1.08) == n) cout << ans << '\n';
	else if (floor((ans + 1) * 1.08) == n)
		cout << ans + 1 << '\n';
	else cout << ":(" << '\n';
	return 0;
}
