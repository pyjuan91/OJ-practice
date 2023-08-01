#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	bool head = true;
	while (getline(cin, s)) {
		string out = "";
		for (auto c : s) {
			if (c == '\"') {
				if (head) out += "``";
				else out += "''";
				head = !head;
			}
			else out += c;
		}
		cout << out << '\n';
	}
	return 0;
}
