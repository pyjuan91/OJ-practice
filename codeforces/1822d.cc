#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, prev, cur;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) cout << "1\n";
		else if (n % 2 == 1) cout << "-1\n";
		else {
			cout << n;
			cur = n - 1;
			bool flip = true;
			for (;;) {
				cout << " " << cur;
				if (cur == 1) break;
				if (flip) {
					cur = n + 1 - cur;
					flip = false;
				}
				else {
					cur = n - 1 - cur;
					flip = true;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}