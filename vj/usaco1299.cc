#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, t, cur_time = 0, cur_haybale = 0, ans = 0, a, b, this_round;
	cin >> n >> t >> a >> b;
	cur_time = a, cur_haybale = b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		this_round = min(a - cur_time, cur_haybale);
		ans += this_round;
		cur_haybale -= this_round;
		cur_time = a;
		cur_haybale += b;
	}
	this_round = min(t - cur_time + 1, cur_haybale);
	ans += this_round;
	cout << ans << '\n';
	return 0;
}
