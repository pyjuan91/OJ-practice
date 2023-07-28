#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b, c;
	string s;
	cin >> n >> s;
	a = b = c = -1;
	for (int i = 0; i < n; i++) {
		if (a == -1 && s[i] == 'A') a = i;
		if (b == -1 && s[i] == 'B') b = i;
		if (c == -1 && s[i] == 'C') c = i;
	}
	cout << max({a, b, c}) + 1 << "\n";
	return 0;
}
