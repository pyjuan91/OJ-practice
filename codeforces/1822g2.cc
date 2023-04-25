#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int t, n, a, res, ma;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> m;
		while (n--) {
			cin >> a;
			m[a] += 1;
		}
		res = 0;
		auto iter = m.end();
		iter--;
		ma = iter->first;
		for (auto p : m) {
			if (p.second >= 3)
				res += (p.second) * (p.second - 1) * (p.second - 2);
			for (int i = 1; i * i <= p.first && p.first * i <= ma; i++) {
				if (p.first % i == 0) {
					if (i != 1 && m.count(p.first / i) && m.count(p.first * i))
						res += p.second * m[p.first / i] * m[p.first * i];
					if (i * i != p.first && m.count(i) && m.count(p.first * p.first / i))
						res += p.second * m[i] * m[p.first * p.first / i];
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}