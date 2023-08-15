#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<bool> vist(n + 1, false);
		for (int i = 1; i <= n; i++) {
			if (vist[i] == false) {
				cout << i << " ";
				vist[i] = true;
				int ii = i;
				while (ii * 2 <= n) {
					cout << ii * 2 << " ";
					vist[ii * 2] = true;
					ii *= 2;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
