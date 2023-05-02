#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, l, r;
	cin >> n >> m;
	vector<int> a(n + 1), select(n + 1, 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i - 1] && a[i] >= a[i + 1]) select[i] = 0;
	select[0] = 0;
	for (int i = 1; i <= n; i++) select[i] += select[i - 1];
	while (m--) {
		cin >> l >> r;
		if (l == r) cout << "1\n";
		else cout << select[r - 1] - select[l] + 2 << "\n";
	}
	return 0;
}