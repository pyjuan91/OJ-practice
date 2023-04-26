#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int t, n, x, n1, n2, p1, p2;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			cin >> n1 >> n2;
			cout << n1 * n2 << "\n";
			continue;
		}
		n1 = n2 = p1 = p2 = 0;
		while (n--) {
			cin >> x;
			if (x > 0) {
				if (p1 == 0) p1 = x;
				else if (p2 == 0) {
					if (x > p1) {
						p2 = p1;
						p1 = x;
					}
					else p2 = x;
				}
				else {
					if (x <= p2) continue;
					else if (x > p2 && x <= p1) p2 = x;
					else {
						p2 = p1;
						p1 = x;
					}
				}
			}
			else if (x < 0) {
				if (n1 == 0) n1 = x;
				else if (n2 == 0) {
					if (x < n1) {
						n2 = n1;
						n1 = x;
					}
					else n2 = x;
				}
				else {
					if (x >= n2) continue;
					else if (x < n2 && x >= n1) n2 = x;
					else {
						n2 = n1;
						n1 = x;
					}
				}
			}
		}
		cout << max(n1 * n2, p1 * p2) << "\n";
	}
	return 0;
}