#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res, x;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (cin >> n && n) {
		res = 0;
		while (n--) cin >> x, pq.push(x);
		while (pq.size() > 1) {
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			res += a + b;
			pq.push(a + b);
		}
		cout << res << '\n';
		while (!pq.empty()) pq.pop();
	}
	return 0;
}
