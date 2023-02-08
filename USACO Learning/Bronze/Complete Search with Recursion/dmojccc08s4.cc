#include <bits/stdc++.h>
using namespace std;
int compute(int op, int a, int b) {
	switch (op) {
		case 0: return a + b;
		case 1: return a - b;
		case 2: return a * b;
		case 3:
			if (b == 0 || a % b != 0) return 1e9;
			return a / b;
		default: break;
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int t;
	vector<int> a(4);
	cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int res = 0;
		do {
			// (((ab)c)d)
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						int ab = compute(i, a[0], a[1]);
						if (ab == 1e9) continue;
						int abc = compute(j, ab, a[2]);
						if (abc == 1e9) continue;
						int abcd = compute(k, abc, a[3]);
						if (abcd <= 24) res = max(res, abcd);
					}
				}
			}
			// ( (ab) (cd) )
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						int ab = compute(i, a[0], a[1]);
						if (ab == 1e9) continue;
						int cd = compute(j, a[2], a[3]);
						if (cd == 1e9) continue;
						int abcd = compute(k, ab, cd);
						if (abcd <= 24) res = max(res, abcd);
					}
				}
			}
			if (res == 24) break;
		} while (next_permutation(a.begin(), a.end()));
		cout << res << "\n";
	}
	return 0;
}