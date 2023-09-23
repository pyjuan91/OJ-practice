#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int tt, n, x, t, hl;
	priority_queue<int> pq;
	cin >> tt;
	while (tt--) {
		cin >> n;
		while (n--) {
			cin >> x;
			pq.emplace(x);
		}
		while (!pq.empty()) {
			t = pq.top();
			pq.pop();
			if (pq.empty()) {
				cout << "T\n";
				goto chaewon;
			}
			hl = pq.top();
			pq.pop();
			if (t > 1) pq.emplace(t - 1);
			if (hl > 1) pq.emplace(hl - 1);
		}
		cout << "HL\n";
	chaewon:;
	}
	return 0;
}
