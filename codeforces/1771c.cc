#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 33334;
vector<int> lp(N + 1);
vector<int> pr;
int a[100005], n;
set<int> s;
bool chaewon() {
	s.clear();
	for (int i = 1; i <= n; ++i) {
		int x = a[i];
		for (auto p : pr) {
			if (p > x) break;
			if (x % p == 0) {
				if (s.count(p)) return true;
				s.insert(p);
				while (x % p == 0) x /= p;
			}
		}
		if (x > 1) {
			if (s.count(x)) return true;
			s.insert(x);
		}
	}
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
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		cout << (chaewon() ? "YES\n" : "NO\n");
	}
	return 0;
}
