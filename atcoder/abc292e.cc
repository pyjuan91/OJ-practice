#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, a, b, res = 0;
	cin >> n >> m;
	vector<vector<int>> edge(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].emplace_back(b);
	}
	for (int i = 1; i < n + 1; i++) {
		vector<bool> used(n + 1, false);
		function<void(int)> chaewon = [&](int cur) {
			used[cur] = true;
			res += 1;
			for (auto e : edge[cur]) {
				if (used[e]) continue;
				chaewon(e);
			}
		};
        chaewon(i);
	}
    cout << res - n - m;
	return 0;
}