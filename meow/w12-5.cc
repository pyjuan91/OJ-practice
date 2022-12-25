#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) { return x & -x; }
int g[1005][1005];
class BIT {
private:
    int n;
    vector<long long> bit;

public:
    void init(int _n)
    {
        n = _n;
        bit.resize(n);
        for (auto& i : bit)
            i = 0;
    }
    long long query(int x) const
    {
        long long sum = 0;
        for (x; x; x -= lowbit(x))
            sum += bit[x];
        return sum;
    }
    void modify(int x, int val)
    {
        for (; x <= n; x += lowbit(x))
            bit[x] += val;
    }
};
class BIT2D {
private:
    int m;
    vector<BIT> bit1D;

public:
    void init(int _m, int _n)
    {
        m = _m;
        bit1D.resize(m);
        for (auto& i : bit1D)
            i.init(_n);
    }
    long long query(int x, int y) const
    {
        long long sum = 0;
        for (x; x; x -= lowbit(x))
            sum += bit1D[x].query(y);
        return sum;
    }
    void modify(int x, int y, int val)
    {
        for (; x <= m; x += lowbit(x))
            bit1D[x].modify(y, val);
    }
    void flip(int x, int y)
    {
        if (g[x][y])
            modify(x, y, -1);
        else
            modify(x, y, 1);
        g[x][y] = !g[x][y];
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, q, cmd, x1, x2, y1, y2;
    char c;
    cin >> m >> q;
    BIT2D iu;
    iu.init(m + 1, m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '*')
                iu.flip(i, j);
        }
    }
    // cout << iu.query(m, m) << endl;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x1 >> y1;
            iu.flip(x1, y1);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            // cout << iu.query(x2, y2) << endl;
            // cout << iu.query(x1, y1) << endl;
            cout << iu.query(x2, y2) - iu.query(x2, y1-1)
                    - iu.query(x1-1, y2) + iu.query(x1-1, y1-1)
                 << "\n";
        }
    }
    return 0;
}