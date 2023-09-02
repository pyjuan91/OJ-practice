#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	string s, l, r;
	cin >> t;
	while (t--) {
		cin >> s >> n >> l >> r;
		vector<int> pos[10];
		if (n > s.length()) {
			cout << "YES\n";
			continue;
		}
		for (int i = 0; i < s.length(); ++i) {
			pos[s[i] - '0'].push_back(i);
		}
		int ma = INT32_MIN, cur;
		for (char c = l[0]; c <= r[0]; c++) {
			if (pos[c - '0'].empty()) {
				cout << "YES\n";
				goto chaewon;
			}
			if (pos[c - '0'][0] > ma) ma = pos[c - '0'][0];
		}
		cur = ma;
		for (int i = 1; i < n; i++) {
			ma = INT32_MIN;
			for (char c = l[i]; c <= r[i]; c++) {
				auto it = upper_bound(
				  pos[c - '0'].begin(), pos[c - '0'].end(), cur);
				if (it == pos[c - '0'].end()) {
					cout << "YES\n";
					goto chaewon;
				}
				if (*it > ma) ma = *it;
			}
            cur = ma;
		}
		cout << "NO\n";
	chaewon:;
	}
	return 0;
}
