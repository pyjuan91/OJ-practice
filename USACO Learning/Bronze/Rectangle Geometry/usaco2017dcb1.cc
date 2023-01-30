#include <bits/stdc++.h>
using namespace std;
int maxn = 2000;
int main() {
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int x1, x2, y1, y2, res = 0;
	vector<vector<bool>> visiable(2005, vector<bool>(2005, false));
	for (int i = 0; i < 3; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += maxn / 2;
		x2 += maxn / 2;
		y1 += maxn / 2;
		y2 += maxn / 2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				visiable[j][k] = i < 2;
			}
		}
	}
	for (int i = 0; i <= maxn; i++) {
		for (int j = 0; j <= maxn; j++) {
			if (visiable[i][j]) res += 1;
		}
	}
	cout << res;
	return 0;
}