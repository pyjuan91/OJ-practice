#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	ifstream cin("bcount.in");
	ofstream cout("bcount.out");
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, q, l, r, x;
	cin >> n >> q;
	vector<vector<int>> pre(3, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		cin >> x;
		pre[x - 1][i]++;
		for (int j = 0; j < 3; j++) pre[j][i] += pre[j][i - 1];
	}
	while (q--) {
		cin >> l >> r;
		for (int i = 0; i < 3; i++)
			cout << pre[i][r] - pre[i][l - 1] << (i == 2 ? '\n' : ' ');
	}
	return 0;
}
