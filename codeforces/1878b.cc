#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int first = 1, second = 3, third;
		cout << first << " " << second << " ";
		for (int i = 3; i <= n; i++) {
			third = second + 1;
			while ((3 * third) % (first + second) == 0) {
				third++;
			}
			cout << third << " ";
			first = second;
			second = third;
		}
        cout << "\n";
	}
	return 0;
}
