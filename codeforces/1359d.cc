#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	for (int bob = 0; bob < 31; bob++) {
		int max_sub = 0;
		for (auto x : a) {
			if (x > bob) {
				max_sub = 0;
				continue;
			}
			max_sub += x;
			if (max_sub < 0) max_sub = 0;
			res = max(res, max_sub - bob);
		}
	}
	cout << res << '\n';
	return 0;
}
