#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	for (int kase = 1; kase <= INT32_MAX; kase++) {
		cin >> s;
		if (s == "#") break;
		cout << "Case " << kase << ": ";
		if (s == "HELLO") cout << "ENGLISH\n";
		else if (s == "HOLA") cout << "SPANISH\n";
		else if (s == "HALLO") cout << "GERMAN\n";
		else if (s == "BONJOUR") cout << "FRENCH\n";
		else if (s == "CIAO") cout << "ITALIAN\n";
		else if (s == "ZDRAVSTVUJTE") cout << "RUSSIAN\n";
		else cout << "UNKNOWN\n";
	}
	return 0;
}
