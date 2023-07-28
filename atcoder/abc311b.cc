#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, d, id = 0, res = 0, idd;
	char c;
	cin >> n >> d;
	vector<bool> a(d, true);
	while (n--) {
		for (int i = 0; i < d; i++) {
			cin >> c;
			if (c == 'x') a[i] = false;
		}
	}
    while(id < d) {
        if(!a[id]) {
            id++;
            continue;
        }
        idd = id;
        while(idd < d && a[idd]) idd++;
        res = max(res, idd - id);
        id = idd;
    }
    cout << res;
	return 0;
}
