#include <bits/stdc++.h>
#define int long long
using namespace std;
int get_digit_sum(int a) {
	int res = 0;
	while (a) {
		res += a % 10;
		a /= 10;
	}
	return res;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m, l, r, cmd;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n + 1);
		set<int> s;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] > 9) s.insert(i);
		}
		while (m--) {
			cin >> cmd;
			if (cmd == 1) {
				cin >> l >> r;
				auto left = s.lower_bound(l), right = s.upper_bound(r);
				while (left != right) {
					a[*left] = get_digit_sum(a[*left]);
					if (a[*left] < 10) {
						auto erase = left;
						left++;
						s.erase(erase);
					}
					else left++;
				}
			}
			else {
				cin >> l;
				cout << a[l] << "\n";
			}
		}
	}
	return 0;
}