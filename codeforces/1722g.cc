#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 4 == 0) {
			int scalar = n / 4;
			for (int i = 0; i < scalar; i++) {
				cout << 1 + 4 * i << " " << 3 + 4 * i << " "
					 << 2 + 4 * i << " " << 4 * i << " ";
			}
			cout << '\n';
		}
		else if (n % 4 == 3) {
			int scalar = (n - 3) / 4;
			for (int i = 1; i <= scalar; i++) {
				cout << 1 + 4 * i << " " << 3 + 4 * i << " "
					 << 2 + 4 * i << " " << 4 * i << " ";
			}
			cout << 1 << " " << 3 << " " << 2 << " ";
			cout << '\n';
		}
		else if (n % 4 == 1) {
			int scalar = (n - 1) / 4;
			for (int i = 1; i <= scalar; i++) {
				cout << 1 + 4 * i << " " << 3 + 4 * i << " "
					 << 2 + 4 * i << " " << 4 * i << " ";
			}
			cout << "0 \n";
		}
		else {
			int scalar = (n - 2) / 4;
			for (int i = 1; i < scalar; i++) {
				cout << 32 + 1 + 4 * i << " " << 32 + 3 + 4 * i << " "
					 << 32 + 2 + 4 * i << " " << 32 + 4 * i << " ";
			}
			cout << "7 9 8 10 0 12\n";
		}
	}
	return 0;
}
