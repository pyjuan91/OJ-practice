#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	deque<int> q, tmp;
	q.push_back(1);
	for (int i = 2; i <= n; i++) {
		q.push_front(0);
		q.push_back(0);
		for (int j = 0; j < q.size() - 1; j++) {
			tmp.push_back(q[j] + q[j + 1]);
		}
		q = tmp;
		tmp.clear();
	}
	int res = 0;
	for (int i : q) {
		res += i;
	}
	cout << res << '\n';
	return 0;
}
