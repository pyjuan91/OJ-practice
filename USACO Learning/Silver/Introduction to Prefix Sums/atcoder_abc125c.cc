#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, res = 1;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i < n + 1; i++) cin >> a[i];
	vector<int> prefix(n + 1), suffix(n + 1);
	prefix[1] = a[1];
	suffix[n] = a[n];
	for (int i = 2; i < n + 1; i++)
		prefix[i] = gcd(prefix[i - 1], a[i]);
	for (int i = n - 1; i > 0; i--)
		suffix[i] = gcd(suffix[i + 1], a[i]);
	for (int i = 2; i < n; i++)
		res = max(res, gcd(prefix[i - 1], suffix[i + 1]));
	res = max({res, prefix[n - 1], suffix[2]});
    cout << res;
	return 0;
}