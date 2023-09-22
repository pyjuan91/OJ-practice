#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int xors, sum;
	cin >> xors >> sum;
	if ((xors + sum) % 2 == 1 || xors > sum) {
		cout << "-1\n";
		return 0;
	}
	if (xors == sum) {
		if (xors == 0) cout << "0\n";
		else cout << "1\n" << xors << "\n";
		return 0;
	}
	int a = xors, b = (sum - xors) / 2;
	if ((a ^ b) + b == sum)
		cout << "2\n" << (a ^ b) << " " << b << "\n";
	else cout << "3\n" << a << " " << b << " " << b << "\n";
	return 0;
}
