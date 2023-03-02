#include <bits/stdc++.h>
using namespace std;
bool e[105][105] = {false};
int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, a, b;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		e[a][b] = true;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 1; k < n + 1; k++) {
				e[j][k] |= e[j][i] & e[i][k];
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		bool sol = true;
		for (int j = 1; j < n + 1; j++) {
			if (j == i) continue;
			sol = sol & e[j][i];
		}
		if (sol) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}