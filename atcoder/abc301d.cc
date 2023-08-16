#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(string& s, int& n) {
	reverse(s.begin(), s.end());
	int len = s.size();
	int fixed = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '1') fixed += (1ll << i);
	}
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] == '?') {
			if (fixed + (1ll << i) <= n) fixed += (1ll << i);
		}
	}
	return fixed <= n ? fixed : -1;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	int n;
	cin >> s >> n;
	cout << chaewon(s, n);
	return 0;
}
