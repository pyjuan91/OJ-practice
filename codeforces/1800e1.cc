#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, len;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s1 >> s2;
		if (s1.length() != s2.length()) {
			cout << "No\n";
			continue;
		}
		len = s1.length();
		int cnt1[26] = {0}, cnt2[26] = {0};
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (i < k && i + k >= n) {
				if (s1[i] != s2[i]) {
					ok = false;
					break;
				}
			}
			else {
				cnt1[s1[i] - 'a']++;
				cnt2[s2[i] - 'a']++;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (cnt1[i] != cnt2[i]) ok = false;
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
