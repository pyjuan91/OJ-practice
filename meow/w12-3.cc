#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;

int n;
int segtree[4 * MAXN], a[MAXN];

void build(int l = 1, int r = n, int node = 1)
{
    if (l == r)
        segtree[node] = a[l];
    else {
        int mid = (l + r) / 2;
        build(l, mid, node * 2);
        build(mid + 1, r, node * 2 + 1);
        segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
    }
}

void queryupdate(int val, int l = 1, int r = n, int node = 1)
{
    if (l == r) {
        segtree[node] -= val;
        cout << l << ' ';
    } else {
        int mid = (l + r) / 2;
        if (segtree[node * 2] >= val)
            queryupdate(val, l, mid, node * 2);
        else
            queryupdate(val, mid + 1, r, node * 2 + 1);

        segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build();

    while (q--) {
        int x;
        cin >> x;
        if (segtree[1] < x)
            cout << "0 ";
        else
            queryupdate(x);
    }
    return 0;
}