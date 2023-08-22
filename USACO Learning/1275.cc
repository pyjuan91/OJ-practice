#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, last_h = 0, last_g = 0;
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'G') last_g = i;
		if (s[i] == 'H') last_h = i;
	}
	// cout << last_g << ' ' << last_h << '\n';
	int lg = 0, lh = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'G' && lg == 0) {
			if (a[i] >= last_g) lg = i;
			else lg = -1;
		}
		if (s[i] == 'H' && lh == 0) {
			if (a[i] >= last_h) lh = i;
			else lh = -1;
		}
	}
	// cout << lg << ' ' << lh << '\n';
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'G') {
			if (i <= lh && a[i] >= lh) res++;
		}
		if (s[i] == 'H') {
			if (i <= lg && a[i] >= lg) res++;
		}
	}
	if (lg != -1 && lh != -1) {
		if (lg < lh) {
			if (a[lg] < lh) res++;
		}
		else {
			if (a[lh] < lg) res++;
		}
	}
	cout << res << '\n';
	return 0;
}
