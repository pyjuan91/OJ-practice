#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	auto is_palin = [](string& s) {
		string t = s;
		reverse(t.begin(), t.end());
		return s == t;
	};

	map<char, char> mirror;

	auto init_mirror = [&]() -> void {
		mirror['A'] = 'A';
		mirror['E'] = '3';
		mirror['3'] = 'E';
		mirror['H'] = 'H';
		mirror['I'] = 'I';
		mirror['J'] = 'L';
		mirror['L'] = 'J';
		mirror['M'] = 'M';
		mirror['O'] = 'O';
		mirror['S'] = '2';
		mirror['2'] = 'S';
		mirror['T'] = 'T';
		mirror['U'] = 'U';
		mirror['V'] = 'V';
		mirror['W'] = 'W';
		mirror['X'] = 'X';
		mirror['Y'] = 'Y';
		mirror['Z'] = '5';
		mirror['5'] = 'Z';
		mirror['1'] = '1';
		mirror['8'] = '8';
	};

	init_mirror();

	auto is_mirror = [&](string& s) {
		string t = s;
		reverse(t.begin(), t.end());
		for (char& c : t) {
			if (!mirror.count(c)) return false;
			c = mirror[c];
		}
		return s == t;
	};

	while (cin >> s) {
		bool palin = is_palin(s);
		bool mirror = is_mirror(s);
		if (palin && mirror)
			cout << s << " -- is a mirrored palindrome.\n\n";
		else if (palin)
			cout << s << " -- is a regular palindrome.\n\n";
		else if (mirror)
			cout << s << " -- is a mirrored string.\n\n";
		else cout << s << " -- is not a palindrome.\n\n";
	}

	return 0;
}

