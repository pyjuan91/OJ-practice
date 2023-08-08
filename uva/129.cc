#include <bits/stdc++.h>
using namespace std;
bool check(string& s) {
	size_t n = s.length();
	for (size_t i = 1; i * 2 <= n; i++) {
		bool all = true;
		for (size_t j = n - (i * 2); j < n - i; j++) {
			if (s[j] != s[j + i]) all = false;
		}
		if (all) return false;
	}
	return true;
}
bool chaewon(int& n, int m, string& s) {
	if (n <= 0) return true;
	for (int i = 0; i < m; i++) {
		s += (char) ('A' + i);
		if (check(s)) {
			if (chaewon(--n, m, s)) return true;
		}
		s.pop_back();
	}
	return false;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m && n) {
		string s = "";
		chaewon(n, m, s);
		for (size_t i = 0; i < s.length(); i++) {
			if (i && i % 64 == 0) cout << "\n";
			else if (i && i % 4 == 0) cout << " ";
			cout << s[i];
		}
		cout << "\n" << s.length() << "\n";
	}
	return 0;
}
