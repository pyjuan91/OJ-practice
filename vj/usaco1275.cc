#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (s[1] == 'H') {
		for (int i = 1; i <= n; i++) {
			if (s[i] == 'H') s[i] = 'G';
			else s[i] = 'H';
		}
	}
	int lh = 0, lg = 0;
	for (int i = n; i >= 1; i--) {
		if (s[i] == 'H' && !lh) lh = i;
		if (s[i] == 'G' && !lg) lg = i;
	}
	int h_head = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'H') {
			if (a[i] >= lh) h_head = i;
			break;
		}
	}
	if (h_head == 0) {
		cout << "0\n";
		return 0;
	}
	int res = 0;
	for (int i = 2; i < h_head; i++) {
		if (s[i] == 'G' && (a[i] >= h_head)) res++;
	}
	if (a[1] >= min(h_head, lg)) res++;
	cout << res << '\n';
	return 0;
}
