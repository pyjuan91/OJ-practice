#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, c, k;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> k;
		int mia = pow(10, a - 1), maa = pow(10, a);
		int mib = pow(10, b - 1), mab = pow(10, b);
		int mic = pow(10, c - 1), mac = pow(10, c);
		for (int i = mia; i < maa; i++) {
			int left = max(mib, mic - i), right = min(mab, mac - i);
			if (left >= mab || right <= mib) continue;
			int consume = right - left;
			if (k > consume) k -= consume;
			else {
				cout << i << " + " << left + k - 1 << " = "
					 << i + left + k - 1 << "\n";
				goto chaewon;
			}
		}
		cout << "-1\n";
	chaewon:;
	}
	return 0;
}