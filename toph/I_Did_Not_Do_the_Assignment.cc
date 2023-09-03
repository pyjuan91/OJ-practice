#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	const string no_pu = "NO PUNISHMENT";
	const string pu = "I DID NOT DO THE ASSIGNMENT.";
	cin >> n;
	auto is_prime = [&](int x) {
		if (x < 2) return false;
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0) return false;
		return true;
	};
    if (is_prime(n)) cout << no_pu << '\n';
    else for (int i = 0; i < n; ++i) cout << pu << '\n';
	return 0;
}
