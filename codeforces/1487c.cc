#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 2) {
			int tar = (n - 1) / 2;
			vector<int> win(n, tar), lose(n, tar);
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (win[i] && lose[j]) {
						cout << 1 << " ";
						win[i]--;
						lose[j]--;
					}
					else {
						cout << -1 << " ";
						lose[i]--;
						win[j]--;
					}
				}
			}
			cout << '\n';
		}
		else {
			int tar = (n - 2) / 2;
			vector<int> win(n, tar), lose(n, tar);
			vector<bool> tie(n, false);
			for (int i = 0; i < n - 1; i++) {
				for (int j = i + 1; j < n; j++) {
					if (!tie[i] && !tie[j]) {
						tie[i] = tie[j] = true;
						cout << 0 << " ";
					}
					else if (win[i] && lose[j]) {
						cout << 1 << " ";
						win[i]--;
						lose[j]--;
					}
					else {
						cout << -1 << " ";
						win[j]--;
						lose[i]--;
					}
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
