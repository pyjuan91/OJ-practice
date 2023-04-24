#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll chaewon(vector<int>& a, int& n) {
	priority_queue<int> pq;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) pq.push(a[i]);
		else if (!pq.empty()) {
			res += 1LL * pq.top();
			pq.pop();
		}
	}
	return res;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << chaewon(a, n) << "\n";
	}
	return 0;
}