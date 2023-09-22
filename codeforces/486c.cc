#include <bits/stdc++.h>
using namespace std;

string s;
int n, p, ans = 0;
int l = -1, r = -1;

int main() {
	cin >> n >> p >> s;
	p--;

	ans += min(abs(s[p] - s[n - p - 1]), 26 - abs(s[p] - s[n - p - 1]));
	if (p >= n / 2) p = n - p - 1;
	for (int i = 0; i < p; i++) {
		if (s[i] != s[n - i - 1]) {
			if (l == -1) l = i;
			ans += min(
			  abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
		}
	}
	for (int i = n / 2 - 1; i > p; i--) {
		if (s[i] != s[n - i - 1]) {
			if (r == -1) r = i;
			ans += min(
			  abs(s[i] - s[n - i - 1]), 26 - abs(s[i] - s[n - i - 1]));
		}
	}
	if (l == -1 && r == -1) {}
	else if (l == -1) ans += abs(p - r);
	else if (r == -1) ans += abs(p - l);
	else ans += min(abs(p - l), abs(p - r)) + abs(l - r);
    cout << ans << endl;
	return 0;
}