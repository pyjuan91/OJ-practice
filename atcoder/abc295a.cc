#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you")
			ans = true;
	}
	if (ans) cout << "Yes";
	else cout << "No";
	return 0;
}