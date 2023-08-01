#include <bits/stdc++.h>
using namespace std;
int chaewon(string& s) {
	auto check = [&](string& sub, size_t& len) {
		for (size_t i = len; i < s.length(); i += len) {
			if (s.substr(i, len) != sub) return false;
		}
		return true;
	};
	for (size_t len = 1; len <= s.length(); ++len) {
		if (s.length() % len == 0) {
			string sub = s.substr(0, len);
			if (check(sub, len)) return len;
		}
	}
	return 0;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	bool first = true;
	cin >> t;
	while (t--) {
		cin >> s;
		if (first) first = false;
		else cout << '\n';
		cout << chaewon(s) << '\n';
	}
	return 0;
}
