#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	auto ask = [&](int l, int r) {
		cout << "? " << l << ' ' << r << endl;
		cout.flush();
	};
	while (t--) {
		cin >> n;
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r) >> 1;
			ask(l, mid);
			int inside_change = 0;
			for (int i = l; i <= mid; i++) {
				cin >> x;
				if (x >= l && x <= mid) inside_change++;
			}
			if (inside_change & 1) r = mid;
            else l = mid + 1;
		}
        cout << "! " << r << endl;
        cout.flush();
	}
	return 0;
}
