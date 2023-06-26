#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int W, H, N, A, B, mi = INT64_MAX, ma = INT64_MIN;
int p[maxn], q[maxn], a[maxn], b[maxn];
map<pair<int, int>, int> m;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	a[0] = b[0] = 0;
	cin >> W >> H >> N;
	for (int i = 0; i < N; i++) cin >> p[i] >> q[i];
	cin >> A;
	for (int i = 1; i <= A; i++) cin >> a[i];
	cin >> B;
	for (int i = 1; i <= B; i++) cin >> b[i];
	a[A + 1] = W;
	b[B + 1] = H;
	for (int i = 0; i < N; i++) {
		int x = *lower_bound(a, a + A + 2, p[i]);
		int y = *lower_bound(b, b + B + 2, q[i]);
		m[make_pair(x, y)] += 1;
	}
	for (auto& ele : m) ma = max(ma, ele.second);
	if ((int) m.size() != (A + 1) * (B + 1)) mi = 0;
	else
		for (auto& ele : m) mi = min(mi, ele.second);
	cout << mi << " " << ma << "\n";
	return 0;
}