#include <bits/stdc++.h>
#define int long long
using namespace std;
void balance(multiset<int> &l, multiset<int> &r) {
	if (l.empty() || r.empty()) return;
	int lv = *(--(l.end())), rv = *r.begin();
	while (lv > rv) {
		l.erase(l.find(lv));
		r.erase(r.find(rv));
		r.insert(lv);
		l.insert(rv);
		lv = *(--(l.end())), rv = *r.begin();
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	if (k == 1) {
		for (auto x : a) cout << x << " ";
		return 0;
	}
	multiset<int> l, r;
	l.insert(a[0]);
	for (int i = 1; i < k - 1; i++) {
		if (l.size() == r.size()) l.insert(a[i]);
		else r.insert(a[i]);
	}
	balance(l, r);
	for (int i = k - 1; i < n; i++) {
		if (l.size() <= r.size()) l.insert(a[i]);
		else r.insert(a[i]);
		balance(l, r);
		cout << *(--(l.end())) << " ";
		if (a[i - k + 1] < *r.begin())
			l.erase(l.find(a[i - k + 1]));
		else r.erase(r.find(a[i - k + 1]));
	}
	return 0;
}