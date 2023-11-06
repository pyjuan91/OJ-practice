#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	auto is_prime = [&](int x) {
		if (x < 2) return false;
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) return false;
		}
		return true;
	};
    cout << (is_prime(n) ? "Yes" : "No");
	return 0;
}
