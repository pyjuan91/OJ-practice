#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int h, w;
	cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w)),
	  b(h, vector<char>(w)), c(h, vector<char>(w));

	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) cin >> a[i][j];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) cin >> b[i][j];

	bool yes = false;
	for (int row_shift = 0; row_shift < h; row_shift++) {
		for (int col_shift = 0; col_shift < w; col_shift++) {
			auto this_check = true;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					c[i][j] = b[(i + row_shift) % h][(j + col_shift) % w];
					if (c[i][j] != a[i][j]) {
						this_check = false;
						goto chaewon;
					}
				}
			}
		chaewon: {}
			if (this_check) {
				yes = true;
				goto yoyo;
			}
		}
	}
yoyo: {}
	if (yes) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}