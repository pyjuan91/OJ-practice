#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char route[] = "snuke";
char g[105][105];
int h, w;
bool chaewon(int x, int y) {
	for (int i = 0; i < 8; i++) {
		bool yes = true;
		for (int j = 1; j < 5; j++) {
			int nx = x + dx[i] * j;
			int ny = y + dy[i] * j;
			if (nx < 1 || nx > h || ny < 1 || ny > w || g[nx][ny] != route[j]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			for (int j = 0; j < 5; j++) {
				int nx = x + dx[i] * j;
				int ny = y + dy[i] * j;
				cout << nx << " " << ny << "\n";
			}
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) cin >> g[i][j];
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (g[i][j] == 's') {
				if (chaewon(i, j)) return 0;
			}
		}
	}

	return 0;
}