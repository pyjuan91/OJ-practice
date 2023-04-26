#include <bits/stdc++.h>
using namespace std;
#define int long long
int chaewon(int n) {
	vector<pair<int, int>> pow_fac;
	int tp = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int pow = 0;
			while (n % i == 0) {
				pow += 1;
				n /= i;
			}
			pow_fac.emplace_back(make_pair(pow, i));
			tp *= i;
		}
	}

	if (n > 1) {
		pow_fac.emplace_back(make_pair(1, n));
		tp *= n;
	}

	sort(pow_fac.begin(), pow_fac.end());
	int res = 0, pre_minus = 0;

	for (auto i : pow_fac) {
		res += (i.first - pre_minus) * tp;
		tp /= i.second;
		pre_minus = i.first;
	}

	return res;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << chaewon(n) << "\n";
	}
	return 0;
}