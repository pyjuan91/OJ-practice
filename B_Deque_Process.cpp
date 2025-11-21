#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n, deque<int>& a) {
	vector<char> res;
	bool decreasing = true;
	while (a.size() >= 2) {
		if (decreasing) {
			if (a.front() > a.back()) {
				res.push_back('L');
				a.pop_front();
			} else {
				res.push_back('R');
				a.pop_back();
			}
			decreasing = false;
		} else {
			if (a.front() < a.back()) {
				res.push_back('L');
				a.pop_front();
			} else {
				res.push_back('R');
				a.pop_back();
			}
			decreasing = true;
		}
	}
	if (a.size() == 1) {
		res.push_back('L');
	}
	for (auto x : res) {
		cout << x;
	}
	cout << '\n';
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		deque<int> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		patty(n, a);
	}
	return 0;
}
