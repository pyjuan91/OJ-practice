#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[105], sum = 0;
bool dp[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	for (int i = 0; i < 200005; i++) dp[i] = false;
	dp[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 200000; j >= 0; j--) {
			if (j + a[i] < 200005 && dp[j]) dp[j + a[i]] = true;
		}
	}
	if (sum % 2 == 1 || !dp[sum / 2]) cout << "0";
	else {
		for (;;) {
			for (int i = 1; i <= n; i++) {
				if (a[i] % 2 == 1) {
					cout << "1\n" << i;
					return 0;
				}
				a[i] /= 2;
			}
		}
	}
	return 0;
}
