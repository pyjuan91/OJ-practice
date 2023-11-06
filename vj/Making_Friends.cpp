#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) res++;
	}
    cout << res;
	return 0;
}
