#include <bits/stdc++.h>
using namespace std;
bool chaewon(string& s) {
	if (s.length() == 0) return true;
	if (s.back() != 'r' && s.back() != 'e' && s.back() != 'm')
		return false;
	switch (s.back()) {
		case 'm':
			if (s.length() < 5) return false;
			if (s.substr(s.length() - 5, 5) != "dream")
				return false;
			for (int i = 0; i < 5; i++)
				s.pop_back();
			return chaewon(s);
			break;
		case 'e':
			if (s.length() < 5) return false;
			if (s.substr(s.length() - 5, 5) != "erase")
				return false;
			for (int i = 0; i < 5; i++)
				s.pop_back();
			return chaewon(s);
		case 'r':
			if (s.length() < 6) return false;
			if (s.substr(s.length() - 6, 6) == "eraser") {
				for (int i = 0; i < 6; i++)
					s.pop_back();
				return chaewon(s);
			}
			else if (s.substr(s.length() - 6, 6) == "reamer") {
				if (s.length() < 7) return false;
				if (s[s.length() - 7] != 'd')
					return false;
				for (int i = 0; i < 7; i++)
					s.pop_back();
				return chaewon(s);
			}
			break;

		default: break;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	string s;
	cin >> s;
	if (chaewon(s)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}