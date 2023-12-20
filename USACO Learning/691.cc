#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	ifstream cin("hps.in");
	ofstream cout("hps.out");
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	char c;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == 'P') a[i] = 0;
		else if (c == 'H') a[i] = 1;
		else a[i] = 2;
	}

	vector<vector<int>> pref_wins(3, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)
			pref_wins[j][i] = pref_wins[j][i - 1];
		pref_wins[a[i]][i]++;
	}

	int res = 0;

	for (int change = 1; change <= n; change++) {
		for (int bef = 0; bef < 3; bef++) {
			for (int aft = 0; aft < 3; aft++) {
				int cur_score = pref_wins[bef][change - 1]
							  + pref_wins[aft][n]
							  - pref_wins[aft][change - 1];
				res = max(res, cur_score);
			}
		}
	}

	cout << res << '\n';

	return 0;
}
