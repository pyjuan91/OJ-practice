#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x, res = 0;
	cin >> n >> x;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	sort(begin(a), end(a));
	for (int i = 0; i < n; i++) {
		if (x < a[i]) break;
		x -= a[i];
		res += 1;
	}
	cout << res;
	return 0;
}