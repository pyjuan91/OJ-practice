#include <bits/stdc++.h>
#define int long long
using namespace std;
bool chaewon(string& s) {
	int closed = 0, quota = 0;
	for (auto c : s) {
		if (c == '(') closed++;
		else if (c == ')') {
			if (closed) closed--;
			else quota--;
		}
		else quota++;
		if (quota == 1 && closed == 0) quota--, closed++;
	}
	return quota == closed;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		if (chaewon(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}