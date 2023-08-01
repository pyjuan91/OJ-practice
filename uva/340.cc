#include <bits/stdc++.h>
using namespace std;
int ans[1005], guess[1005];
bool considered[1005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, kase = 1;
	while (cin >> n && n) {
		cout << "Game " << kase++ << ":\n";
		for (int i = 0; i < n; i++) cin >> ans[i];
		for (;;) {
			bool br = true;
			for (int i = 0; i < n; i++) {
				cin >> guess[i];
				if (guess[i]) br = false;
			}
			if (br) break;

			int a = 0, b = 0;
			memset(considered, false, sizeof(considered));
			for (int i = 0; i < n; i++)
				if (ans[i] == guess[i])
					a++, considered[i] = true;

			int ans_cnt[10] = {}, guess_cnt[10] = {};
			for (int i = 0; i < n; i++) {
				if (!considered[i]) {
					ans_cnt[ans[i]]++;
					guess_cnt[guess[i]]++;
				}
			}

			for (int i = 0; i < 10; i++)
				b += min(ans_cnt[i], guess_cnt[i]);
			cout << "    (" << a << "," << b << ")\n";
		}
	}
	return 0;
}
