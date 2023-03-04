#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n, q, l, r;
	cin >> n >> q;
	vector<int> a(n + 1, 0);
	for (int i = 1; i < n + 1; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	while (q--) {
		cin >> l >> r;
		cout << a[r] - a[l] << "\n";
	}
	return 0;
}