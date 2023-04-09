#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	string s;
	cin >> s;
	bool bishop, king_rook;
	int left = -1, right = -1, mid;
	for (int i = 0; i < 8; i++)
		if (s[i] == 'B') {
			if (left == -1) left = i;
			else right = i;
		}
	bishop = (left % 2 != right % 2);
	left = -1;
	for (int i = 0; i < 8; i++) {
		if (s[i] == 'R') {
			if (left == -1) left = i;
			else right = i;
		}
		if (s[i] == 'K') mid = i;
	}
	king_rook = (left < mid && mid < right);
	if (king_rook && bishop) cout << "Yes";
	else cout << "No";
	return 0;
}