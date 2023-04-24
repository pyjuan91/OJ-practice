#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int sum = 0, x, min_pos = 1e9 + 5, max_neg = -1e9 - 5, neg_num = 0;
		while (n--) {
			cin >> x;
			sum += abs(x);
			if (x < 0) {
				neg_num += 1;
				max_neg = max(x, max_neg);
			}
			else min_pos = min(x, min_pos);
		}
		if (neg_num % 2 == 1) {
			if (min_pos < -max_neg) sum -= 2 * min_pos;
			else sum += 2 * max_neg;
		}
		cout << sum << "\n";
	}
	return 0;
}