#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;

		auto chaewon = [](auto n) {
			for (int root = 2; root <= 64; root++) {
				int kguess = pow(n, 1.0 / root * 1.0);
				if (kguess < 2) break;
				int sum = 1, powers = 1;
				for (int r = 1; r <= root; r++) {
					powers *= kguess;
					sum += powers;
				}
				if (sum == n) return true;
			}
			return false;
		};

		if (chaewon(n)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}