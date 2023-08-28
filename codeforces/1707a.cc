#include <bits/stdc++.h>
using namespace std;
int a[100005];
string chaewon(int n, int q) {
	if (q >= n) return string(n, '1');
	int cq = 0;
	string res = "";
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > cq && cq < q) {
			cq++;
			res.push_back('1');
		}
		else if (a[i] <= cq) res.push_back('1');
		else res.push_back('0');
	}
    reverse(res.begin(), res.end());
    return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, q;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << chaewon(n, q) << "\n";
	}
	return 0;
}
