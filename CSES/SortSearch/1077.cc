#include <bits/stdc++.h>
#define int long long
using namespace std;
void balance(multiset<int>& l, multiset<int>& r, int& ls, int& rs) {
	if (l.empty() || r.empty()) return;
	int lv = *l.rbegin(), rv = *r.begin();
	while (lv > rv) {
		l.erase(l.find(lv));
		r.erase(r.find(rv));
		l.insert(rv);
		r.insert(lv);
		ls -= lv, ls += rv;
		rs -= rv, rs += lv;
		lv = *l.rbegin(), rv = *r.begin();
	}
}
int get_cost(multiset<int>& l, multiset<int>& r, int& ls, int& rs) {
	int median = *l.rbegin();
	return median * l.size() - ls + rs - median * r.size();
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, ls = 0, rs = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a) cin >> x;
	multiset<int> l, r;
	if (k == 1) {
		for (int i = 0; i < n; i++) cout << 0 << " ";
		return 0;
	}
	l.insert(a[0]), ls += a[0];
	for (int i = 1; i < k - 1; i++) {
		if (l.size() == r.size()) l.insert(a[i]), ls += a[i];
		else r.insert(a[i]), rs += a[i];
	}
	balance(l, r, ls, rs);
	for (int i = k - 1; i < n; i++) {
		if (l.size() <= r.size()) l.insert(a[i]), ls += a[i];
		else r.insert(a[i]), rs += a[i];
		balance(l, r, ls, rs);
		cout << get_cost(l, r, ls, rs) << " ";
		int bound = *r.begin();
		if (a[i - k + 1] >= bound)
			r.erase(r.find(a[i - k + 1])), rs -= a[i - k + 1];
		else l.erase(l.find(a[i - k + 1])), ls -= a[i - k + 1];
	}
	return 0;
}