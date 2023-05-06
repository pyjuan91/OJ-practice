#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, time, one_time, two_time, both_time;
	string sk;
	cin >> t;
	while (t--) {
		cin >> n;
		one_time = two_time = both_time = 1e8;
		while (n--) {
			cin >> time >> sk;
			if (sk == "10") one_time = min(one_time, time);
			else if (sk == "01") two_time = min(two_time, time);
			else if (sk == "11")
				both_time = min(both_time, time);
		}
		if (both_time == 1e8 && (one_time == 1e8 || two_time == 1e8))
			cout << "-1\n";
		else
			cout << min(one_time + two_time, both_time) << "\n";
	}
	return 0;
}