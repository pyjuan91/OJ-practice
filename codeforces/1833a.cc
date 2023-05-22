#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		set<string> se;
		for (int i = 0; i < n - 1; i++)
			se.insert(s.substr(i, 2));
		cout << se.size() << "\n";
	}
	return 0;
}