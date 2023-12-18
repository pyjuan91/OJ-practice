#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		bool has_solved = false;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != '0') {
				a = stoi(s.substr(0, i));
				b = stoi(s.substr(i));
				if (a < b) {
					has_solved = true;
					break;
				}
			}
		}
		if (has_solved) cout << a << " " << b << "\n";
		else cout << "-1\n";
	}
	return 0;
}
