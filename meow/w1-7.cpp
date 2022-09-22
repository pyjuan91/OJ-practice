#include <bits/stdc++.h>
using namespace std;
void helper(vector<int>& v, int n, int m, int pos, int cur, vector<int> res)
{
    if (cur == m) {
        cout << res[0];
        for (int i = 1; i < m; i++)
            cout << " " << res[i];
        cout << "\n";
        return;
    }
    for (int i = pos; i < n; i++) {
        res[cur] = v[i];
        helper(v, n, m, i + 1, cur + 1, res);
    }
}
int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> res(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    helper(v, n, m, 0, 0, res);
    return 0;
}