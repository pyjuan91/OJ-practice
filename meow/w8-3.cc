#include <iostream>
#include <vector>
using namespace std;

int n, a, b, sz[200005];
long long ans[200005];
vector<int> v[200005];

void dfs(int x, int pre, int d)
{
    ans[1] += d;
    for (auto i : v[x]) {
        if (i == pre)
            continue;
        dfs(i, x, d + 1);
        sz[x] += sz[i];
    }
    sz[x]++;
}

void dfs2(int x, int pre)
{
    for (auto i : v[x]) {
        if (i == pre)
            continue;
        ans[i] = ans[x] + (n - sz[i]) - (sz[i]);
        dfs2(i, x);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}