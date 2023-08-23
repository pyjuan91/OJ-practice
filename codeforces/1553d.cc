#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		if (s1 == s2) {
			cout << "YES\n";
			continue;
		}
		int len1 = s1.length(), len2 = s2.length();
		if (len1 < len2) {
			cout << "NO\n";
			continue;
		}
		int start = ((len1 - len2) % 2) ? 1 : 0;
		int complete = 0;
		for (int i = start; i < len1; i++) {
			if (s1[i] != s2[complete]) i++;
			else complete++;
			if (complete == len2) break;
		}
		if (complete == len2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
