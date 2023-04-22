#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	string s;
	int n;
	cin >> n;
	cin >> s;
	int a = -1, b = -1, c = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '|') {
			if (a == -1) a = i;
			else c = i;
		}
		if (s[i] == '*') b = i;
	}
	if (b >= a && b <= c) cout << "in";
	else cout << "out";
	return 0;
}