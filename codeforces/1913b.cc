#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int n = s.size(), cnt[2] = {};
		for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (cnt[1] == 0) {
					cout << n - i << "\n";
					goto end;
				}
				else cnt[1]--;
			}
			else {
				if (cnt[0] == 0) {
					cout << n - i << "\n";
					goto end;
				}
				else cnt[0]--;
			}
		}
		cout << "0\n";
	end:;
	}
	return 0;
}
