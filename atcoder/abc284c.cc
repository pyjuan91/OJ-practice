#include <bits/stdc++.h>
using namespace std;
class DJS {
public:
    int n;
    vector<int> parent;
    DJS(int _n)
    {
        parent.resize(_n + 1);
        n = _n;
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
    int FindRoot(int a)
    {
        if (parent[a] == a)
            return a;
        return parent[a] = FindRoot(parent[a]);
    }
    bool SameUnion(int a, int b)
    {
        if (FindRoot(a) == FindRoot(b))
            return true;
        return false;
    }
    void Unite(int a, int b)
    {
        parent[FindRoot(a)] = FindRoot(b);
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    DJS djs(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        djs.Unite(a, b);
    }
    unordered_set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(djs.FindRoot(i));
    cout << s.size();
    return 0;
}