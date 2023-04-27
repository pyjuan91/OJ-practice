#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k, x, wrong_num;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		wrong_num = 0;

		for (int i = 1; i <= n; i++) {
			cin >> x;
			if (x % k != i % k) wrong_num += 1;
		}

		if (wrong_num == 0) cout << "0\n";
		else if (wrong_num == 2) cout << "1\n";
		else cout << "-1\n";
	}
	return 0;
}