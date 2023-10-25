#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string a, b;
	while (cin >> a >> b) {
		if (a == "0" && b == "0") break;
		int carry = 0, carry_cnt = 0;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (int i = 0; i < max(a.size(), b.size()); ++i) {
			int x = i < a.size() ? a[i] - '0' : 0;
			int y = i < b.size() ? b[i] - '0' : 0;
			if (x + y + carry >= 10) {
				carry = 1;
				++carry_cnt;
			}
			else carry = 0;
		}
		if (carry_cnt == 0) cout << "No carry operation.\n";
		else if (carry_cnt == 1) cout << "1 carry operation.\n";
		else cout << carry_cnt << " carry operations.\n";
	}
	return 0;
}
