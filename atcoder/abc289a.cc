#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	for (auto& c : str) {
		if (c == '0') c = '1';
		else c = '0';
	}
	cout << str;
	return 0;
}