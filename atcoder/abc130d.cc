#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
#define int long long
	int n, k, prefix = 0, res = 0;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<int> s;
	for (int i = 0; i < n; i++) {
		prefix += a[i];
		if (prefix >= k) {
			auto iter = upper_bound(s.begin(), s.end(), prefix - k);
            res += distance(s.begin(), iter) + 1;
		}
        s.emplace_back(prefix);
	}
    cout << res;
	return 0;
}