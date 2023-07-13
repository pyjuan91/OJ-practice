#include <bits/stdc++.h>
#define int long long
using namespace std;
int s[105], t, n, k;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> s[i];
		sort(s, s + n);
		bool over_two = false;
		for (int i = 0; i < n - 2; i++)
			if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
				over_two = true;
		cout << "Case #" << kase << ": ";
		if (over_two || n > 2 * k) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}