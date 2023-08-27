#include <bits/stdc++.h>
using namespace std;
char a[3005][3005], b[3005][3005];
int triangle[3005][3005];
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j], b[i][j] = a[i][j];
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				triangle[i][j] = 0;
				if (i == 0) {
					if (b[i][j] == '1') {
						res++;
						triangle[i][j] = 1;
					}
				}
				else if (i == 1) {
					triangle[i][j] = 0;
					if (j > 0)
						triangle[i][j] ^= triangle[i - 1][j - 1];
					if (j < n - 1)
						triangle[i][j] ^= triangle[i - 1][j + 1];
					triangle[i][j] ^= triangle[i - 1][j];
					if (triangle[i][j] ^ (b[i][j] - '0')) {
						res++;
						triangle[i][j] ^= 1;
						a[i][j] = '1';
					}
					else a[i][j] = '0';
				}
				else {
					triangle[i][j] = 0;
					if (j == 0) {
						triangle[i][j] ^= triangle[i - 1][j + 1];
						triangle[i][j] ^= (a[i - 1][j] - '0');
					}
					else if (j == n - 1) {
						triangle[i][j] ^= triangle[i - 1][j - 1];
						triangle[i][j] ^= (a[i - 1][j] - '0');
					}
					else {
						triangle[i][j] ^= triangle[i - 2][j];
						triangle[i][j] ^= triangle[i - 1][j - 1];
						triangle[i][j] ^= triangle[i - 1][j + 1];
						triangle[i][j] ^= (a[i - 1][j] - '0');
					}
					if (triangle[i][j] ^ (b[i][j] - '0')) {
						res++;
						triangle[i][j] ^= 1;
						a[i][j] = '1';
					}
					else a[i][j] = '0';
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}