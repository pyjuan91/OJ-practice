#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
	setIO("maxcross");
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, k, b, x;
	cin >> n >> k >> b;
	vector<int> a(n + 1, 0);
	while (b--) {
		cin >> x;
		a[x] += 1;
	}
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	int res = n;
	for (int i = 0; i <= n - k; i++)
		res = min(res, a[i + k] - a[i]);
	cout << res;
	return 0;
}