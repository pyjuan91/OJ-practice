#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i += 2)
		if (i + 1 < s.length()) swap(s[i], s[i + 1]);
	cout << s;
	return 0;
}