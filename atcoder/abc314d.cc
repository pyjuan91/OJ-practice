#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
struct Query {
		int op, x;
		char c;
		Query() {}
};
Query q[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	string s;
	pair<int, int> last = make_pair(-1, -1);
	cin >> n >> s >> m;
	for (int i = 0; i < m; i++) {
		cin >> q[i].op >> q[i].x >> q[i].c;
		if (q[i].op == 2 || q[i].op == 3) {
			last = make_pair(q[i].op, i);
		}
	}
	if (last.first == -1) {
		for (int i = 0; i < m; i++) {
			if (q[i].op == 1) s[q[i].x - 1] = q[i].c;
		}
	}
	else if (last.first == 2) {
		transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
			return tolower(c);
		});
		for (int i = 0; i < last.second; i++) {
			if (q[i].op == 1) {
				if (q[i].c >= 'A' && q[i].c <= 'Z')
					q[i].c = q[i].c - 'A' + 'a';
				s[q[i].x - 1] = q[i].c;
			}
		}
		for (int i = last.second + 1; i < m; i++) {
			if (q[i].op == 1) s[q[i].x - 1] = q[i].c;
		}
	}
	else {
		transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
			return toupper(c);
		});
		for (int i = 0; i < last.second; i++) {
			if (q[i].op == 1) {
				if (q[i].c >= 'a' && q[i].c <= 'z')
					q[i].c = q[i].c - 'a' + 'A';
				s[q[i].x - 1] = q[i].c;
			}
		}
		for (int i = last.second + 1; i < m; i++) {
			if (q[i].op == 1) s[q[i].x - 1] = q[i].c;
		}
	}
	cout << s << "\n";
	return 0;
}
