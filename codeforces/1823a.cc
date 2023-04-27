#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n * (n - 1) / 2 == k) {
			cout << "YES\n1";
			for (int i = 1; i < n; i++) cout << " 1";
			cout << "\n";
		}
		else if (n * (n - 1) / 2 < k) { cout << "NO\n"; }
		else {
			int tar = (n * n - 2 * k - n) / 2, i = 1;
			for (i = 1; i <= n / 2; i++) {
				if (i * (n - i) == tar) {
					cout << "YES\n1";
					for (int j = 1; j < i; j++) cout << " 1";
					for (int j = i; j < n; j++) cout << " -1";
					cout << "\n";
					goto chaewon;
				}
			}
			cout << "NO\n";
		chaewon: {}
		}
	}
	return 0;
}