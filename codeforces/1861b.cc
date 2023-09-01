#include <bits/stdc++.h>
using namespace std;
bool chaewon(string& s1, string& s2) {
	int len = s1.length();
	for (int i = 0; i < len; i++) {
		if (s1[i] == '0' && s2[i] == '0') continue;
		else if (s1[i] == '1' && s2[i] == '1') return true;
		else {
			int j = i + 1;
			bool ok = false;
			while (j < len) {
				if (s1[j] == '0' && s2[j] == '0') {
					ok = true;
					break;
				}
				j++;
			}
			if (ok) i = j;
			else return false;
		}
	}
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> s1 >> s2;
		if (chaewon(s1, s2)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
