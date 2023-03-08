#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, q, a, b;
	cin >> n >> q;
	vector<int> kind(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> kind[i];
	vector<vector<int>> chaewon(4, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			chaewon[j][i] = chaewon[j][i - 1];
		chaewon[kind[i]][i] += 1;
	}
	// for (int i = 1; i <= 3; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << chaewon[i][j] << " ";
	// 	cout << endl;
	// }
	while (q--) {
		cin >> a >> b;
		for (int i = 1; i <= 3; i++) {
			cout << chaewon[i][b] - chaewon[i][a - 1];
			if (i < 3) cout << " ";
		}
		cout << "\n";
	}
	return 0;
}