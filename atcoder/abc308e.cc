#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	string s;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> s;
	vector<vector<int>> left(n + 2, vector<int>(3, 0)),
	  right(n + 2, vector<int>(3, 0));
	for (int i = 1; i <= n; i++) {
		left[i] = left[i - 1];
		if (s[i - 1] == 'M') left[i][a[i]]++;
	}
	for (int i = n; i >= 1; i--) {
		right[i] = right[i + 1];
		if (s[i - 1] == 'X') right[i][a[i]]++;
	}
	auto mex = [&](int x, int y, int z) {
		for (int i = 0; i < 3; i++) {
			if (i != x && i != y && i != z) return i;
		}
		return (int) 3;
	};
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'E') {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					res += left[i - 1][j] * right[i + 1][k]
						 * mex(j, k, a[i]);
				}
			}
		}
	}
	cout << res << '\n';
	return 0;
}
