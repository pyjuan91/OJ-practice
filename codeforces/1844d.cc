#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	const char s[] = "abcdefghijklmnopqrstuvwxyz";
	cin >> t;
	while (t--) {
		cin >> n;
		int nu = 1;
		for (; nu <= n; nu++)
			if (n % nu != 0) break;
        for(int i = 0; i < n; i++)
            cout << s[i % nu];
        cout << '\n';
	}
	return 0;
}
