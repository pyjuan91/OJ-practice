#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int x;
	cin >> x;
	auto is_leap
	  = [&](int x) { return x % 4 == 0 && x % 400 != 0; };
    cout << (is_leap(x) ? "Yes" : "No");
	return 0;
}
