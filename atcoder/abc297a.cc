#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, d, res = -1, last, cur;
	cin >> n >> d >> last;
	for (int i = 1; i < n; i++) {
		cin >> cur;
		if (cur - last <= d && res == -1) res = cur;
		last = cur;
	}
	cout << res;
	return 0;
}