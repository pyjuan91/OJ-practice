#include <bits/stdc++.h>
#define int long long
using namespace std;
string chaewon(int n) {
	if (n == 1) return "a";
	if (n == 2) return "ab";
	if (n == 3) return "abc";
	if (n % 2 == 1) {
		n -= 2;
		string res;
		for (int i = 0; i < n / 2; i++) res.push_back('a');
		res.push_back('b');
		res.push_back('c');
		for (int i = 0; i <= n / 2; i++) res.push_back('a');
		return res;
	}
	n -= 1;
	string res;
	for (int i = 0; i < n / 2; i++) res.push_back('a');
	res.push_back('b');
	for (int i = 0; i <= n / 2; i++) res.push_back('a');
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << chaewon(n) << "\n";
	}
	return 0;
}
