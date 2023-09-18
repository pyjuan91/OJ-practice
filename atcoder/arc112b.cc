#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int b, c;
	cin >> b >> c;
	if (b == 0) cout << c;
	else if (c == 0) cout << 1;
	else if (b > 0)
		cout << 2 + (c - 1) / 2 + (c - 2) / 2 + min(b, c / 2)
				  + min(b - 1, (c - 1) / 2);
	else
		cout << 2 + c / 2 + (c - 1) / 2 + min(-b, (c - 1) / 2)
				  + min(-b - 1, (c - 2) / 2);
	return 0;
}
