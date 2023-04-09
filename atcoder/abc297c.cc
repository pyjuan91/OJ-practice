#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int h, w;
	string s;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int i = 0; i < w - 1; i++) {
			if (s[i] != 'T') continue;
			if (s[i + 1] == 'T') {
				s[i] = 'P';
				s[i + 1] = 'C';
			}
		}
		cout << s << "\n";
	}
	return 0;
}