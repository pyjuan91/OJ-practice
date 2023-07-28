#include <bits/stdc++.h>
#define int long long
int nxt[200005];
bool vis[200005];
using namespace std;
void chaewon(int x, vector<int>& cycle, int& rp) {
    vis[x] = true;
    cycle.push_back(x);
    if (vis[nxt[x]]) {
        rp = nxt[x];
        return;
    }
    chaewon(nxt[x], cycle, rp);
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(vis, false, sizeof(vis));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nxt[i];
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vector<int> cycle;
		int rp = -1;
        chaewon(i, cycle, rp);
        if(rp !=  -1) {
            for(auto iter = cycle.begin();iter!=cycle.end();iter++) {
                if(*iter == rp) {
                    vector<int> res;
                    for(;iter!=cycle.end();iter++) {
                        res.emplace_back(*iter);
                    }
                    cout << res.size() << "\n";
                    for(auto x:res) cout << x << " " ;
                    return 0;
                }
            }
        }
	}
	return 0;
}
