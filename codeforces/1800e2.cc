#include <bits/stdc++.h>
using namespace std;
bool chaewon(string& s1, string& s2, int& n, int& k) {
	for (int i = 0; i < n; i++) {
		if (s1[i] != s2[i] && i < k && i + k >= n) return false;
	}
	sort(begin(s1), end(s1));
	sort(begin(s2), end(s2));
	return s1 == s2;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k;
	string s1, s2;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s1 >> s2;
		if (chaewon(s1, s2, n, k)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}