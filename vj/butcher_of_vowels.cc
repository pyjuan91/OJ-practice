#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		auto is_evil = [&](const string& s) {
			for (char c : s) {
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
					return true;
			}
			return false;
		};
		cout << (is_evil(s) ? "Yes" : "No") << '\n';
	}
	return 0;
}
