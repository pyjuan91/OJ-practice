#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
vector<pii> prime_factors(int x, int k) {
	vector<pii> res;
	for (int i = 2; i * i <= x; i++) {
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt += 1;
		}
		if (cnt % k) res.emplace_back(make_pair(i, cnt % k));
	}
	if (x > 1) res.emplace_back(make_pair(x, 1));
	return res;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, k, res = 0, x;
	cin >> n >> k;
	map<vector<pii>, int> m;
	while (n--) {
		cin >> x;
		auto current = prime_factors(x, k);
		vector<pii> complement;
		for (auto& p : current)
			complement.emplace_back(make_pair(p.first, k - p.second));
		if (m.count(complement)) res += m[complement];
		m[current] += 1;
	}
    cout << res;
	return 0;
}