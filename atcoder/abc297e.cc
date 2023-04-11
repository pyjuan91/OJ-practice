#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int n, k, prev = -1;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pq.push(a[i]);
	}

	for (;;) {
		if (prev != pq.top()) prev = pq.top();
		else {
			pq.pop();
			continue;
		}
		pq.pop();
		k -= 1;
		if (k == 0) break;
		for (int i = 0; i < n; i++) pq.push(prev + a[i]);
	}
	cout << prev;
	return 0;
}