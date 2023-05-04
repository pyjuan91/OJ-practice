#include <bits/stdc++.h>
using namespace std;
void solve(int& n, int& k) {
	int d = 0;
	while (d * (d + 1) / 2 <= k) d += 1;
	d -= 1;

	// d's 2
	for (int i = 0; i < d; i++) cout << "2 ";
	// complement =  k - d;
	k -= d * (d + 1) / 2;
	if (k) cout << -((d - k) * 2) - 1 << " ";
	for (int i = k ? d + 1 : d; i < n; i++) cout << "-1000 ";
	cout << "\n";
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		solve(n, k);
	}
	return 0;
}