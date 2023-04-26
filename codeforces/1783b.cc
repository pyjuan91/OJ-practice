#include <bits/stdc++.h>
using namespace std;
void chaewon(int n) {
	int cur_value = 1, cur_sign = 1, cur_diff = n * n - 1;
	vector<vector<int>> res;
	for (int i = 0; i < n; i++) {
		vector<int> tmp;
		for (int j = 0; j < n; j++) {
			tmp.emplace_back(cur_value);
			cur_value += cur_sign * cur_diff;
			cur_sign *= -1;
			cur_diff -= 1;
		}
		if (i & 1) reverse(tmp.begin(), tmp.end());
		res.emplace_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i][0];
		for (int j = 1; j < n; j++) cout << " " << res[i][j];
		cout << "\n";
	}
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		chaewon(n);
	}
	return 0;
}