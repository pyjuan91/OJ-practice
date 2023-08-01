#include <bits/stdc++.h>
using namespace std;
string a[105];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		size_t len = s.length();
		for (size_t i = 0; i < len; i++) {
			a[i] = s.substr(i, len - i) + s.substr(0, i);
		}
        sort(a, a + len);
        cout << a[0] << '\n';
	}
	return 0;
}
