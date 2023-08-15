#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<string> a(m);
		vector<int> b(m);
		vector<bool> done(n, false), consi(m, true);
		for (int i = 0; i < m; ++i) cin >> a[i] >> b[i];
		for (int cal = 0; cal < n; cal++) {
			for (int i = 0; i < n; i++) {
				if (done[i]) continue;
				int one_tag = -1, zero_tag = -1;
				bool one_determined = true, zero_determined = true;
				for (int j = 0; j < m; j++) {
					if (consi[j]) {
						if (a[j][i] == '1') {
							if (one_tag == -1) {
								one_tag = b[j];
							}
							else if (one_tag != b[j]) {
								one_determined = false;
							}
						}
						else {
							if (zero_tag == -1) {
								zero_tag = b[j];
							}
							else if (zero_tag != b[j]) {
								zero_determined = false;
							}
						}
					}
				}
				if (one_determined && zero_determined) {
					cout << "OK\n";
					goto chaewon;
				}
				if (one_determined) {
					done[i] = true;
					for (int j = 0; j < m; j++)
						if (a[j][i] == '1') consi[j] = false;
				}
				if (zero_determined) {
					done[i] = true;
					for (int j = 0; j < m; j++)
						if (a[j][i] == '0') consi[j] = false;
				}
			}
		}
		cout << "LIE\n";
	chaewon:;
	}
	return 0;
}
