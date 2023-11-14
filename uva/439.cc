#include <bits/stdc++.h>
using namespace std;
int chaewon(const string& s, const string& t) {
	int sx = s[0] - 'a', sy = s[1] - '1';
	int tx = t[0] - 'a', ty = t[1] - '1';
	const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
	const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	auto valid = [&](int x, int y) {
		return x >= 0 && x < 8 && y >= 0 && y < 8;
	};
	bool vis[8][8] = {};
	queue<int> qx, qy, qd;
	qx.push(sx), qy.push(sy), qd.push(0);
	vis[sx][sy] = true;
	while (!qx.empty()) {
		int x = qx.front();
		qx.pop();
		int y = qy.front();
		qy.pop();
		int d = qd.front();
		qd.pop();
		if (x == tx && y == ty) return d;
		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (!valid(nx, ny) || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			qx.push(nx), qy.push(ny), qd.push(d + 1);
		}
	}
    return -1;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, t;
	while (cin >> s >> t) {
		cout << "To get from " << s << " to " << t << " takes ";
		cout << chaewon(s, t) << " knight moves.\n";
	}
	return 0;
}
