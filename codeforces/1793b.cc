#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << 2 * (a - b) << "\n";
		if (2 * (a - b) == 2) cout << a << " " << b << "\n";
		else {
			cout << a;
			for (int i = a - 1; i >= b; i--) cout << " " << i;
			for (int i = b + 1; i < a; i++) cout << " " << i;
			cout << "\n";
		}
	}
	return 0;
}