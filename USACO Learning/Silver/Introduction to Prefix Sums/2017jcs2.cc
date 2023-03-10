#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, res = 0;
	cin >> n;
	vector<int> s(n + 1, 0), h(n + 1, 0), p(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		switch (c) {
			case 'S': s[i] = 1; break;
			case 'H': h[i] = 1; break;
			case 'P': p[i] = 1; break;
			default: break;
		}
		s[i] += s[i - 1];
		h[i] += h[i - 1];
		p[i] += p[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		res = max(
			res, max({s[i], h[i], p[i]})
						 + max({s[n] - s[i], h[n] - h[i], p[n] - p[i]}));
	}
	cout << res;
	return 0;
}