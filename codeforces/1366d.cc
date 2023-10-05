#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	//cp-algorithm: linear sieve
	const int N = 10000000;
	vector<int> lp(N + 1);
	vector<int> pr;

	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) { break; }
		}
	}

	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x, xx, sz, p, candi1, candi2;
	cin >> n;
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		xx = x;
		vector<int> pf;
		while (xx > 1) {
			p = lp[xx];
			pf.push_back(p);
			while (xx % p == 0) xx /= p;
		}
		sz = pf.size();
		for (int cond = 1; cond < (1 << sz) - 1; cond++) {
			candi1 = candi2 = 1;
			for (int j = 0; j < sz; j++) {
				if (cond & (1 << j)) candi1 *= pf[j];
				else candi2 *= pf[j];
			}
			if (__gcd(candi1 + candi2, x) == 1) {
				d1[i] = candi1;
				d2[i] = candi2;
				goto chaewon;
			}
		}
		d1[i] = d2[i] = -1;
	chaewon:;
	}

	for (int i = 0; i < n; i++)
		cout << d1[i] << (i == n - 1 ? '\n' : ' ');
	for (int i = 0; i < n; i++)
		cout << d2[i] << (i == n - 1 ? '\n' : ' ');
	return 0;
}
