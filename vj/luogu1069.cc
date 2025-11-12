#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;

const int kMax = 1e7 + 5;
vector<int> lp(kMax + 1);
vector<int> pr;

int init = []() {
	for (int i = 2; i <= kMax; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= kMax; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}
	return 0;
}();

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	vector<int> a(n);
	for (auto& x : a) {
		cin >> x;
	}
	if (m1 == 1) {
		cout << "0\n";
		return 0;
	}

	auto get_factors = [](int x) -> map<int, int> {
		map<int, int> res;
		if (x <= kMax) {
			while (x > 1) {
				res[lp[x]]++;
				x /= lp[x];
			}
		} else {
			// Trial division for large numbers
			for (int i = 2; i * i <= x; i++) {
				while (x % i == 0) {
					res[i]++;
					x /= i;
				}
			}
			if (x > 1) {
				res[x]++;
			}
		}
		return res;
	};

	map<int, int> m1_fac = get_factors(m1);
	for (auto& p : m1_fac) {
		p.second *= m2;
	}

	auto divide = [&](map<int, int>& a, map<int, int>& b) -> int {
		int res = 0;
		for (const auto& [prime, cnt] : a) {
			if (!b.count(prime)) {
				return -1;
			}
			int need = (cnt + b[prime] - 1) / b[prime];
			res = max(res, need);
		}
		return res;
	};

	int res = INT64_MAX;
	for (const auto& x : a) {
		if (x == 1) {
			continue;
		}
		map<int, int> x_fac = get_factors(x);
		int d = divide(m1_fac, x_fac);
		if (d != -1) {
			res = min(res, d);
		}
	}

	if (res == INT64_MAX) {
		cout << "-1\n";
	} else {
		cout << res << "\n";
	}

	return 0;
}
