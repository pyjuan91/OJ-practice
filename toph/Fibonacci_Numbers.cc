#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a = 1, b = 1, c = 2;
	cin >> n;
	for (int i = 4; i <= n; i++) {
		a = b + c;
		swap(a, b);
		swap(b, c);
	}
    cout << c << '\n';
	return 0;
}
