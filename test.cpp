#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 100;

vector<int> s(maxn);
vector<int> vis(maxn);

bool cmp(int a, int b)
{
    return a > b;
}

int num, len;
int n;

bool dfs(int done, int now, int last)
{
    if (done >= num)
        return true;
    if (now == len)
        return dfs(done + 1, 0, 1);
    int fail = 0; //剪枝1：不重复插入上一个失败的木棍长度
    for (int i = last; i <= n; i++) {
        //剪枝2：构造一根原始木棍时按递减插入，
        // 因为先插入x后插入y和先插入y后插入x是一样的
        if (!vis[i] && now + s[i] <= len /*&& s[i] != fail*/) {
            vis[i] = 1;
            if (dfs(done, now + s[i], i + 1))
                return true;
            vis[i] = 0;
            /*fail = s[i];*/
            if (now == 0 || now + s[i] == len)
                return false;
            //剪枝3，4.如果当前木棍是0或当前木棍以拼成功，却失败了，则说明无解
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n && n) {
        int to = 0;
        int maxx = 0;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            to += s[i];
            // maxx = max(maxx, s[i]);
        }
        sort(s.begin() + 1, s.begin() + n + 1, greater<int>());
        maxx = s[1];
        for (int i = maxx; i <= to; i++) {
            if (to % i == 0) {
                len = i;
                num = to / i;
                // memset(vis, 0, sizeof(vis));
                fill(vis.begin(), vis.end(), false);
                if (dfs(0, 0, 1)) {
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}