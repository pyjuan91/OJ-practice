#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), record_gcd(n + 1);
	for (auto &x : a) cin >> x;
	for (int i = n - 1; i > 0; i--)
		record_gcd[i] = gcd(record_gcd[i + 1], a[i]);
	int res = a[0] * record_gcd[1] / gcd(a[0], record_gcd[1]);
	for (int i = 1; i < n; i++)
		res = gcd(
		  res, a[i] * record_gcd[i + 1] / gcd(a[i], record_gcd[i + 1]));
    cout << res;

	return 0;
}