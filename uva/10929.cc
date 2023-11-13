#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string x;
	while (cin >> x) {
		if (x == "0") break;
		int odd = 0, even = 0;
		for (int i = 0; i < x.length(); i++) {
			if (i % 2 == 0) even += x[i] - '0';
			else odd += x[i] - '0';
		}
		if (abs(odd - even) % 11 == 0)
			cout << x << " is a multiple of 11.\n";
		else cout << x << " is not a multiple of 11.\n";
	}
	return 0;
}
