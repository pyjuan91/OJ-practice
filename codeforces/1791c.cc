#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t, n, l, r;
	string str;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> str;
		l = 0, r = n - 1;
		while (l < r) {
			if (str[l] == str[r]) break;
			l++, r--;
		}
		cout << r - l + 1 << "\n";
	}
	return 0;
}