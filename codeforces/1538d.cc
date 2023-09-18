#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100000;
vector<int> lp(N + 1);
vector<int> pr;
bool chaewon(int a, int b, int k) {
	int g = __gcd(a, b), mi, ma = 0;
	if (a != g && b != g) mi = 2;
	else if (a == g && b == g) mi = 0;
	else mi = 1;
	for (auto& p : pr) {
		while (a % p == 0) {
			a /= p;
			++ma;
		}
		while (b % p == 0) {
			b /= p;
			++ma;
		}
	}
	if (a != 1) ++ma;
	if (b != 1) ++ma;
	if (k == 1 && mi == 0) return false;
	if (k >= mi && k <= ma) return true;
	return false;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
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
	int t, a, b, k;
	cin >> t;
	while (t--) {
		cin >> a >> b >> k;
		if (chaewon(a, b, k)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
