#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	auto convert = [&](auto& bp) {
		int res = 0ll;
		for (int i = 0; i < 32; i++) res += bp[i] * (1ll << i);
		return res;
	};
	function<int(int, int)> go = [&](int apline, int b) {
		vector<int> res;
		int x = 0, flag = 0;
		bitset<32> ap(apline), bp(b);
		for (int i = 31; i >= 0; i--) {
			if (flag) bp[i] = 0;
			else if (ap[i] == 1 && bp[i] == 0)
				flag = 1, bp[i] = 1;
		}
		return convert(bp);
	};
	function<int(int, int)> chaewon = [&](int a, int b) {
		int res = b - a;
		for (int apline = a; apline < b; apline++) {
			int temp = go(apline, b);
			res = min(res, (apline | temp) + apline + 1 - a - b);
		}
		return res;
	};
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << chaewon(a, b) << '\n';
	}
	return 0;
}
