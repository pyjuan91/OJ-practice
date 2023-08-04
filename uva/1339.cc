#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, t;
	while (cin >> s >> t) {
		int n = s.size(), m = t.size();
		if (n != m) {
			cout << "NO\n";
			continue;
		}
		int a[26] = {}, b[26] = {};
		for (int i = 0; i < n; ++i) {
			++a[s[i] - 'A'];
			++b[t[i] - 'A'];
		}
		sort(a, a + 26);
		sort(b, b + 26);
		bool ok = true;
		for (int i = 0; i < 26; ++i) {
			if (a[i] != b[i]) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}
