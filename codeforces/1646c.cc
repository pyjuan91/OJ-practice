#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<int> powerful;
	int factor = 1;
	for (int i = 1; i <= 10000 && i * factor <= 1e12; i++) {
		factor *= i;
		powerful.push_back(factor);
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		auto ppct = [](int n) {
			int res = 0;
			while (n) {
				res += n & 1;
				n >>= 1;
			}
			return res;
		};
		function<int(int, int)> chaewon;
		chaewon = [&](int n, int bound) {
			if (n == 0 || n == 1) return n;
			int res = ppct(n);
			for (int i = bound; i >= 0; i--) {
				if (n >= powerful[i]) {
					res = min(res, 1 + chaewon(n - powerful[i], i - 1));
				}
			}
			return res;
		};
		cout << chaewon(n, powerful.size() - 1) << '\n';
	}
	return 0;
}
