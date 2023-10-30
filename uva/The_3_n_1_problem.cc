#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	auto chaewon = [&](int x) {
		int res = 1;
		while (x != 1) {
			if (x % 2 == 0) x /= 2;
			else x = 3 * x + 1;
			res++;
		}
		return res;
	};
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int l, r;
	while (std::cin >> l >> r) {
		cout << l << " " << r << " ";
        if(l > r) swap(l, r);
		int res = 0;
		for (; l <= r; l++) { res = max(res, chaewon(l)); }
		cout << res << "\n";
	}
	return 0;
}
