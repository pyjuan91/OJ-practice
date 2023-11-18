#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	while (cin >> s) {
		int res = 0, a[3] = {};
		for (auto c : s) {
			if (isdigit(c)) a[0]++;
			else if (islower(c)) a[1]++;
			else a[2]++;
			if (a[0] && a[1] && a[2]) {
				res++;
				a[0] = a[1] = a[2] = 0;
			}
		}
		cout << res << '\n';
	}
	return 0;
}
