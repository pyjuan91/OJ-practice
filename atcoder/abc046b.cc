#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << (int) pow(k - 1, n - 1) * k << '\n';
	return 0;
}
