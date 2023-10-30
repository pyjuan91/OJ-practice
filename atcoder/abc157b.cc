#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int bingo[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) cin >> bingo[i][j];
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (bingo[i][j] == x) bingo[i][j] = 0;
			}
		}
	}
	bool ok = false;
	for (int i = 0; i < 3; i++) {
		bool hori = true, vert = true;
		for (int j = 0; j < 3; j++) {
			if (bingo[i][j] != 0) hori = false;
			if (bingo[j][i] != 0) vert = false;
		}
		ok = ok || hori || vert;
	}
	if (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0)
		ok = true;
	if (bingo[0][2] == 0 && bingo[1][1] == 0 && bingo[2][0] == 0)
		ok = true;
	cout << (ok ? "Yes" : "No");
	return 0;
}
