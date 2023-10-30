#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (n == 1 || m == 1) cout << 1;
	else
		cout << n * (int) (m / 2ll) + (int) ((m % 2ll) * (n + 1) / 2);
	return 0;
}
