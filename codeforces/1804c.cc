#include <bits/stdc++.h>
using namespace std;
#define int long long
bool chaewon(int n, int x, int p) {
	int sum = x;
	for (int i = 1; i <= min(2 * n, p); i++) {
		sum = (sum + i) % n;
		if (sum == 0) return true;
	}
	return false;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, x, p;
	cin >> t;
	while (t--) {
		cin >> n >> x >> p;
		if (chaewon(n, x, p)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}