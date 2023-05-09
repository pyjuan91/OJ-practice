#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		map<pair<int, int>, int> m;
		int d_num = 0, k_num = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'D') d_num += 1;
			else k_num += 1;

			if (d_num == 0) {
				cout << m[{0, 1}] + 1 << " ";
				m[{0, 1}] += 1;
			}
			else if (k_num == 0) {
				cout << m[{1, 0}] + 1 << " ";
				m[{1, 0}] += 1;
			}
			else {
				int gcd = __gcd(d_num, k_num);
				int k_cop = k_num / gcd, d_cop = d_num / gcd;
				cout << m[{d_cop, k_cop}] + 1 << " ";
				m[{d_cop, k_cop}] += 1;
			}
		}
		cout << "\n";
	}
	return 0;
}