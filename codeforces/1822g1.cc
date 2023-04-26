#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int t, n, a, res;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> m;
		while (n--) {
			cin >> a;
			m[a] += 1;
		}
		res = 0;
		for (auto p : m) {
			if (p.second >= 3)
				res += (p.second) * (p.second - 1) * (p.second - 2);
			for (int i = 2; i <= 1000; i++) {
				if (p.first * i * i > 1e6) break;
				if (m.count(p.first * i) && m.count(p.first * i * i)) {
					res += p.second * m[p.first * i] * m[p.first * i * i];
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}