#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int a, b, c, m, res = 0, val, sum;
	string port_type;
	priority_queue<int, vector<int>, greater<int>> usb, ps;
	cin >> a >> b >> c >> m;
	sum = a + b + c;
	while (m--) {
		cin >> val >> port_type;
		if (port_type[0] == 'U') usb.push(val);
		else ps.push(val);
	}
	while (a && !usb.empty()) {
		res += usb.top();
		a -= 1;
		usb.pop();
	}
	while (b && !ps.empty()) {
		res += ps.top();
		b -= 1;
		ps.pop();
	}
	while (c && (!usb.empty() || !ps.empty())) {
		if (usb.empty()) {
			res += ps.top();
			ps.pop();
		}
		else if (ps.empty()) {
			res += usb.top();
			usb.pop();
		}
		else {
			if (usb.top() < ps.top()) {
				res += usb.top();
				usb.pop();
			}
			else {
				res += ps.top();
				ps.pop();
			}
		}
		c -= 1;
	}
	cout << sum - a - b - c << " " << res << "\n";
	return 0;
}