#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b;
    c = pow(a, b) + pow(b, a);
	cout << c << '\n';
	return 0;
}
