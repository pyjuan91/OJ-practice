#include <bits/stdc++.h>
using namespace std;
void chaewon(int n) {
	vector<int> bi;
	int x = n;
	while (x) {
		bi.push_back(x & 1);
		x >>= 1;
	}
	vector<int> res = {n};
	int len = bi.size();
	for (int i = 0; i < len - 1; i++) {
		if (bi[i]) res.push_back(res.back() - (1 << i));
	}
	while (res.back() != 1) res.push_back(res.back() >> 1);
    cout << res.size() << '\n';
	for (auto x : res) cout << x << ' ';
    cout << '\n';
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		chaewon(n);
	}
	return 0;
}
