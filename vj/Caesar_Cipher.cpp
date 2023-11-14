#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	int shift;
	string s, yo = "abcdefghijklmnopqrstuvwxyz";
	cin >> shift;
    getchar();
	getline(cin, s);
	for (auto c : s) {
		if (c == ' ') cout << c;
		else cout << yo[(c - 'a' - shift + 26) % 26];
	}
	return 0;
}
