#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	auto is_palin = [&](const string& s) {
		int n = s.length();
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] != s[n - i - 1]) return false;
		}
		return true;
	};
	cout << (is_palin(s) ? "Yes" : "No");
	return 0;
}
