#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void pull(ll id, vector<ll>& seg)
{
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
void build_tree(vector<ll>& seg,
    ll left, ll right, ll vertex, vector<ll>& v)
{
    if (left == right) {
        seg[vertex] = v[left];
        return;
    }

    ll mid = left + (right - left) / 2;
    build_tree(seg, left, mid, vertex * 2, v);
    build_tree(seg, mid + 1, right, vertex * 2 + 1, v);
    pull(vertex, seg);
}
ll query(ll ql, ll qr, ll left, ll right, vector<ll>& seg,
    ll id = 1)
{
    if (qr < left || ql > right)
        return 2e9;
    if (ql <= left && qr >= right)
        return seg[id];
    ll mid = left + (right - left) / 2;
    return min(query(ql, qr, left, mid, seg, id * 2),
        query(ql, qr, mid + 1, right, seg, id * 2 + 1));
}
void update(ll pos, ll val, ll left, ll right, vector<ll>& seg,
    ll id = 1)
{
    if (pos < left || pos > right)
        return;
    if (left == right) {
        seg[id] = val;
        return;
    }
    ll mid = left + (right - left) / 2;
    update(pos, val, left, mid, seg, id * 2);
    update(pos, val, mid + 1, right, seg, id * 2 + 1);
    pull(id, seg);
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define int long long
    int n, q, a, b, cmd;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> seg(4 * n);
    build_tree(seg, 1, n, 1, v);
    // for (auto i : seg) {
    //     cout << i << " ";
    // }
    // cout << endl;
    while (q--) {
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            update(a, b, 1, n, seg, 1LL);
        } else {
            cout << query(a, b, 1, n, seg, 1LL) << "\n";
        }
    }
    return 0;
}