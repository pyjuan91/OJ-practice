#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n;
	char c;
	set<char> s;
	s.insert('c');
	s.insert('o');
	s.insert('d');
	s.insert('e');
	s.insert('f');
	s.insert('o');
	s.insert('r');
	s.insert('c');
	s.insert('e');
	s.insert('s');
	cin >> n;
	while (n--) {
		cin >> c;
		if (s.find(c) == s.end()) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}