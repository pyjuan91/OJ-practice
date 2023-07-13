#include <bits/stdc++.h>
#define int long long
using namespace std;
bool chaewon(int r, int c, vector<string> &g) {
	if (r > 1 && c > 1) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) g[i][j] = '^';
		return true;
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (g[i][j] == '^') return false;
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, r, c;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> r >> c;
		vector<string> g(r);
		for (auto &s : g) cin >> s;
		cout << "Case #" << kase << ": ";
		if (!chaewon(r, c, g)) cout << "Impossible\n";
		else {
			cout << "Possible\n";
			for (auto &s : g) cout << s << "\n";
		}
	}
	return 0;
}