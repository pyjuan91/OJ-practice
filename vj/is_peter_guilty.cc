#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == 1) cout << "YES\n";
	else if (b + c + d > 1) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
