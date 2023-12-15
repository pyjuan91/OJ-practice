#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int left = 1, right, k, res = 0;
	cin >> right >> k;
	while (left < right) {
		int ask = (left + right) / 2;
		if (k > ask) left = ask + 1;
		else right = ask;
		res++;
	}
	cout << res << endl;
	return 0;
}
