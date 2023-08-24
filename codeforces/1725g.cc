#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	int small[]
	  = {0, 3, 5, 7, 8, 9, 11, 12, 13, 15, 16, 17, 19, 20};
	int big[]
	  = {0, 1, 3, 4, 5, 7, 8, 9, 11, 12, 13, 15, 16, 17, 19};
	if (n <= 13) cout << small[n];
	else cout << (n + 2) / 15 * 20 + (big[(n + 2) % 15]);
	return 0;
}
