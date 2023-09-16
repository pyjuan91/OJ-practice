#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, id = 0, cnt = 0;
	cin >> n >> m;
	deque<int> dq;
	for (int i = 1; i <= n; ++i) dq.push_back(i);
	while (!dq.empty()) {
		for (int i = 1; i < m; i++) {
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << dq.front() << " ";
		dq.pop_front();
	}
	return 0;
}
