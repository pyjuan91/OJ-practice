#include <bits/stdc++.h>
#define int long long
#define f(i, a, b) for (int i = a; i < b; i++)
using namespace std;
int W, H, N, rec[11][3], used[100][100];
void fill(int x, int y, int w, int h) {
	f(i, x, x + w) f(j, y, y + h) used[i][j] = 1;
}
void clear(int x, int y, int w, int h) {
	f(i, x, x + w) f(j, y, y + h) used[i][j] = 0;
}
bool valid(int x, int y, int w, int h) {
	if (x + w > W || y + h > H) return false;
	f(i, x, x + w) f(j, y, y + h) if (used[i][j]) return false;
	return true;
}
int chaewon() {
	f(i, 0, W) {
		f(j, 0, H) {
			if (used[i][j]) continue;
			int res = 0;
			f(k, 1, N + 1) {
				if (rec[k][0]) {
					if (valid(i, j, rec[k][1], rec[k][2])) {
						fill(i, j, rec[k][1], rec[k][2]);
						rec[k][0]--;
						res += chaewon();
						clear(i, j, rec[k][1], rec[k][2]);
						rec[k][0]++;
					}
					if (rec[k][1] != rec[k][2] && valid(i, j, rec[k][2], rec[k][1])) {
						fill(i, j, rec[k][2], rec[k][1]);
						rec[k][0]--;
						res += chaewon();
						clear(i, j, rec[k][2], rec[k][1]);
						rec[k][0]++;
					}
				}
			}
			return res;
		}
	}
	return 1;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	while (cin >> W >> H >> N) {
		memset(used, 0, sizeof(used));
		f(i, 1, N + 1) cin >> rec[i][0] >> rec[i][1] >> rec[i][2];
		cout << chaewon() << '\n';
	}
	return 0;
}
