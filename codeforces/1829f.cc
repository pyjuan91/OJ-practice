#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m, a, b, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> connects(n + 1, 0);
		while (m--) {
			cin >> a >> b;
			connects[a] += 1;
			connects[b] += 1;
		}
		map<int, int> num_cnt;
		for (int i=1;i<=n;i++) num_cnt[connects[i]] += 1;
		// cout << "map\n";
		// for (auto p : num_cnt)
		// 	cout << p.first << " " << p.second << endl;
		if (num_cnt.size() == 3) {
			auto p1 = num_cnt.begin(), p2 = num_cnt.begin();
			p1++, p1++, p2++;
			if (p2->second == p1->first) {
				x = p2->second;
				y = p2->first - 1;
			}
			else {
				x = p1->second;
				y = p1->first - 1;
			}
		}
		else {
			auto p = num_cnt.begin();
			p++;
			x = p->first;
			y = p->first - 1;
		}
		cout << x << " " << y << "\n";
	}
	return 0;
}