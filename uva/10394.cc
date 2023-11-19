#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int, int>> twin_primes;
const int N = 20000000;
vector<int> lp(N + 1);
vector<int> pr;
void linear_sieve() {
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
}
void init() {
	for (int i = 0; i + 1 < pr.size() - 1; i++) {
		if (pr[i + 1] - pr[i] == 2) {
			twin_primes.push_back({pr[i], pr[i + 1]});
		}
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	linear_sieve();
	init();
    // cout << twin_primes.size() << '\n';
	while (cin >> n) {
		cout << "(" << twin_primes[n - 1].first << ", "
			 << twin_primes[n - 1].second << ")\n";
	}
	return 0;
}
