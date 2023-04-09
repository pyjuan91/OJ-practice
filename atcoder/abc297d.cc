#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int a, b, res = 0;
	cin >> a >> b;
	while (a != b) {
		// cout << a << " " << b << endl;
		if (a > b) {
			res += a / b - (a % b == 0 ? 1 : 0);
			a = a % b;
			if (a == 0) break;
		}
		else {
			res += b / a - (b % a == 0 ? 1 : 0);
			b = b % a;
			if (b == 0) break;
		}
		// cout << res << endl;
	}
	cout << res;
	return 0;
}