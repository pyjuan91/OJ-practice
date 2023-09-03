#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cout << i << '\n';
	}
	return 0;
}
