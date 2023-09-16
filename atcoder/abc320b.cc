#include <bits/stdc++.h>
using namespace std;
bool is_palinedrome(string& s) {
	int n = s.size();
	for (int i = 0; i < n / 2; ++i) {
		if (s[i] != s[n - i - 1]) { return false; }
	}
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j + i <= n; j++) {
			string t = s.substr(j, i);
			if (is_palinedrome(t)) {
				cout << t.size() << '\n';
				return 0;
			}
		}
	}
	return 0;
}
