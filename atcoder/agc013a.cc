#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, res = 0, last, x, i;
	bool increasing = true;
	cin >> n;
	vector<int> a(n);
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++) {
		res += 1;
		if (i + 1 == n) break;
		while (i + 1 < n && a[i + 1] == a[i]) i += 1;
		increasing = a[i + 1] > a[i];
		for (i = i + 1; i < n; i++) {
			if (increasing) {
				if (a[i] < a[i - 1]) break;
			}
			else if (a[i] > a[i - 1]) break;
		}
		i -= 1;
	}
	cout << res;
	return 0;
}