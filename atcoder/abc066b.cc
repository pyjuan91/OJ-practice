#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	int n = s.length();
	for (int i = n - 2; i > 0; i -= 2) {
		auto check = [&](int n) {
			for (int i = 0; i < n / 2; i++) {
				if (s[i] != s[n / 2 + i]) return false;
			}
			return true;
		};
		if (check(i)) {
			cout << i << '\n';
			return 0;
		}
	}
	return 0;
}
