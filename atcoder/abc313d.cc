#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	auto ask = [&](vector<int>& q) {
		cout << "?";
		for (const auto& x : q) cout << " " << x + 1;
		cout << endl;
		cout.flush();
		int res;
		cin >> res;
		return res;
	};
	int n, k, sum = 0;
	cin >> n >> k;
	vector<int> a(n, 0), q;
	for (int i = 0; i <= k; i++) {
		q.clear();
		for (int j = 0; j <= k; j++)
			if (i != j) q.push_back(j);
		a[i] = ask(q);
		sum ^= a[i];
	}
	for (int i = 0; i <= k; i++) a[i] ^= sum;
	sum = 0;
	for (int i = 0; i < k - 1; i++) q[i] = i, sum ^= a[i];
	for (int i = k + 1; i < n; i++) {
		q[k - 1] = i;
		a[i] = ask(q);
		a[i] ^= sum;
	}
	cout << "!";
	for (const auto& x : a) cout << " " << x;
	cout << endl;
	cout.flush();
	return 0;
}