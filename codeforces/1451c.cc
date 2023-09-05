#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	string a, b;
	cin >> t;
	while (t--) {
		cin >> n >> k >> a >> b;
		vector<int> cnta(26), cntb(26);
		for (char c : a) cnta[c - 'a']++;
		for (char c : b) cntb[c - 'a']++;
		auto check = [&]() {
			for (int i = 0; i < 26; i++) {
				if (cnta[i] < cntb[i]) return false;
				if (cnta[i] == cntb[i]) continue;
				int passing = cnta[i] - cntb[i];
				if (passing % k) return false;
				cnta[i + 1] += passing;
			}
			return true;
		};
		if (check()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
