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
		int left = 0, right = 0;
		for (int i = 0; i < 3; i++) left += s[i] - '0';
		for (int i = 3; i < 6; i++) right += s[i] - '0';
		cout << (left == right ? "YES\n" : "NO\n");
	}
	return 0;
}
