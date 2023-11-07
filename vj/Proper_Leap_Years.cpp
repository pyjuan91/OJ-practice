#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	auto is_leap = [](int x) {
		if (x % 400 == 0) return true;
		if (x % 100 == 0) return false;
		if (x % 4 == 0) return true;
		return false;
	};
    cout << (is_leap(n) ? "Yes" : "No") << "\n";
	return 0;
}
