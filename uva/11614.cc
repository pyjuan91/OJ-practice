#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	auto chaewon = [&](int x) {
		int guess = floor(sqrt(x * 2)) - 1;
		for (; guess * (guess + 1) / 2 <= x; guess++)
			;
		return guess - 1;
	};

	cin.tie(nullptr)->sync_with_stdio(false);
	int t, x;
	cin >> t;
	while (t--) {
		cin >> x;
		cout << chaewon(x) << '\n';
	}
	return 0;
}
