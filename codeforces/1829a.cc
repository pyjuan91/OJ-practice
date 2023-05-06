#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t;
	string s, cf = "codeforces";
	cin >> t;
	while (t--) {
		cin >> s;
		int res = 0;
		for (int i = 0; i < 10; i++)
			if (s[i] != cf[i]) res += 1;
		cout << res << "\n";
	}
	return 0;
}