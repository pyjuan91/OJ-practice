#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, sum = 0, dec = 0, inc = 0;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, sum += x;
	sort(v.begin(), v.end());
	int avg = sum / n;
	if (sum % n == 0) {
		for (auto x : v) {
			if (x < avg) dec += avg - x;
			else if (x > avg) inc += x - avg;
		}
		cout << dec << "\n";
	}
	else {
		for (auto x : v) {
			if (x < avg) dec += avg - x;
			else if (x > avg + 1) inc += x - avg - 1;
		}
		cout << max(dec, inc) << "\n";
	}
	return 0;
}
