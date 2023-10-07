#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;

struct Node {
		int l, r, ma;
		Node() { l = r = ma = 0; }
} t[4 * maxn];

string s;
int n, m, l, r;

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s >> m;
	n = s.length();

	auto merge = [&](const Node& a, const Node& b) {
		Node c;
		int match = min(a.l, b.r);
		c.l = a.l + b.l - match;
		c.r = a.r + b.r - match;
		c.ma = a.ma + b.ma + match;
		return c;
	};

	function<void(int, int, int)> build = [&](int id, int l, int r) {
		if (l == r) {
			if (s[l] == '(') t[id].l = 1;
			else t[id].r = 1;
		}
		else {
			int mid = (l + r) / 2;
			build(id * 2, l, mid);
			build(id * 2 + 1, mid + 1, r);
			t[id] = merge(t[id * 2], t[id * 2 + 1]);
		}
	};

	function<Node(int, int, int, int, int)> query
	  = [&](int id, int tar_l, int tar_r, int id_cover_l, int id_cover_r) {
		if (id_cover_l >= tar_l && id_cover_r <= tar_r)
			return t[id];
		if (id_cover_l > tar_r || id_cover_r < tar_l)
			return Node();
		int mid = (id_cover_l + id_cover_r) / 2;
		return merge(
		  query(id * 2, tar_l, tar_r, id_cover_l, mid),
		  query(id * 2 + 1, tar_l, tar_r, mid + 1, id_cover_r));
	};

	build(1, 0, n - 1);

	while (m--) {
		cin >> l >> r;
		cout << query(1, l - 1, r - 1, 0, n - 1).ma * 2 << '\n';
	}
	return 0;
}