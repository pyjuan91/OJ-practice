#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x, res = 0;
	priority_queue<int> pq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	while (m-- && !pq.empty()) {
		int t = pq.top();
		pq.pop();
		if (t / 2) pq.push(t / 2);
	}
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    cout << res << '\n';
	return 0;
}
