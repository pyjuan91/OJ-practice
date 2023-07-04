#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, q, cmd, a, b, n, hl, hr;
	cin >> t;
	while (t--) {
		cin >> q;
		hl = hr = -1;
		while (q--) {
			cin >> cmd >> a >> b;
			if (cmd == 1 && cin >> n) {
				if (hl == -1) {
					hl = n != 1 ? (a - b) * (n - 2) + a + 1 : 1;
					hr = (a - b) * (n - 1) + a;
					cout << "1 ";
				}
				else {
					int nhl = n != 1 ? (a - b) * (n - 2) + a + 1 : 1;
					int nhr = (a - b) * (n - 1) + a;
					if (nhr < hl || nhl > hr) cout << "0 ";
					else {
						cout << "1 ";
						hl = max(hl, nhl), hr = min(hr, nhr);
					}
				}
			}
			else {
				if (hl == -1) cout << "-1 ";
				else {
					int lb, rb;
					if (hl <= a) lb = 1;
					else
						lb = ceil((double) (hl - a) / (double) (a - b)) + 1;
					if (hr <= a) rb = 1;
					else
						rb = ceil((double) (hr - a) / (double) (a - b)) + 1;
					// cout << "hl: " << hl << " hr: " << hr << endl;
					if (lb == rb) cout << lb << " ";
					else cout << "-1 ";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}