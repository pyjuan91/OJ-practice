#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int T, t, q, op, a, b, c, d;
	string s1, s2;
	cin >> T;
	while (T--) {
		cin >> s1 >> s2 >> t >> q;
		set<int> diff_pos;
		for (int i = 1; i <= (int) s1.length(); i++)
			if (s1[i - 1] != s2[i - 1]) diff_pos.insert(i);
		queue<pair<int, int>> block_event;
		for (int i = 0; i < q; i++) {
			if (!block_event.empty() && block_event.front().second == i) {
				if (
				  s1[block_event.front().first - 1]
				  != s2[block_event.front().first - 1])
					diff_pos.insert(block_event.front().first);
				block_event.pop();
			}
			cin >> op;
			if (op == 3) {
				if (diff_pos.empty()) cout << "YES\n";
				else cout << "NO\n";
			}
			else if (op == 1) {
				cin >> a;
				diff_pos.erase(a);
				block_event.push(make_pair(a, i + t));
			}
			else {
				cin >> a >> b >> c >> d;
				if (a == c && c == 1)
					swap(s1[b - 1], s1[d - 1]);
				if (a == c && c == 2)
					swap(s2[b - 1], s2[d - 1]);
				if (a != c && c == 1)
					swap(s2[b - 1], s1[d - 1]);
				if (a != c && c == 2)
					swap(s1[b - 1], s2[d - 1]);
				if (s1[b - 1] == s2[b - 1]) diff_pos.erase(b);
				else diff_pos.insert(b);
				if (s1[d - 1] == s2[d - 1]) diff_pos.erase(d);
				else diff_pos.insert(d);
			}
		}
	}
	return 0;
}