#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int b[3], res, quota;
	cin >> b[0] >> b[1] >> b[2];
	sort(b, b + 3);
	res = quota = b[0];
	b[1] -= b[0];
	b[2] -= b[0];
	b[0] = 0;
	if (b[1] * 2 >= b[2]) {
		res += (b[1] + b[2]) / 3;
		cout << res << '\n';
		return 0;
	}
    res += b[1];
	b[2] -= b[1] * 2;
	b[1] = 0;
	res += min(quota, b[2] / 3);
    cout << res << '\n';
	return 0;
}
