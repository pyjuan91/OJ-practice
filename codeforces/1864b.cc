#include <bits/stdc++.h>
using namespace std;
string chaewon(int n, int k, string& s) {
	if (k % 2) {
		string odd = "", even = "";
		for (int i = 0; i < n; i += 2) even += s[i];
		for (int i = 1; i < n; i += 2) odd += s[i];
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		string sol = "";
		int i = 0, j = 0;
		for (int _ = 0; _ < n; _++) {
			if (_ % 2) sol += odd[i++];
			else sol += even[j++];
		}
		return sol;
	}
	sort(s.begin(), s.end());
	return s;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		cout << chaewon(n, k, s) << '\n';
	}
	return 0;
}
