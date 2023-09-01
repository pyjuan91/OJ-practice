#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int one = 0, three = 0;
		for (int i = 0; i < 10; i++) {
			if (s[i] == '1') one = i;
			if (s[i] == '3') three = i;
		}
		if (one < three) cout << "13\n";
		else cout << "31\n";
	}
	return 0;
}
