#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[201][201];
void init() {
	for (int i = 1; i <= 200; i++) a[i][1] = i;
	for (int i = 1; i <= 200; i++)
		for (int j = 2; j <= 200; j++)
			a[i][j] = a[i][j - 1] + 1024;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	init();
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << n * m << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}