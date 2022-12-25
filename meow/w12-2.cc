#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node {
    ll data, tag;
    Node()
    {
        data = tag = 0LL;
    }
};
ll get_val(ll, ll, ll, vector<Node>&);
void pull(ll, ll, ll, vector<Node>&);
void push(ll, ll, ll, vector<Node>&);
ll query(ll, ll, ll, ll, ll, vector<Node>&);
void update(ll, ll, ll, ll, ll, ll, vector<Node>&);
void build_tree(vector<Node>&, ll, ll, ll, vector<ll>&);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define int ll
    int n, q, cmd, a, b, k;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<Node> seg(4 * n);
    build_tree(seg, 1, n, 1, v);
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b >> k;
            update(a, b, k, 1, n, 1, seg);
        } else {
            cin >> k;
            cout << query(k, k, 1, n, 1, seg) << "\n";
        }
    }
    return 0;
}
int get_val(int left, int right, int id, vector<Node>& seg)
{
    return (right - left + 1) * seg[id].tag + seg[id].data;
}
void pull(int left, int right, int id, vector<Node>& seg)
{
    int mid = left + (right - left) / 2;
    seg[id].data = get_val(left, mid, id * 2, seg)
        + get_val(mid + 1, right, id * 2 + 1, seg);
}
void push(int left, int right, int id, vector<Node>& seg)
{
    seg[id].data = get_val(left, right, id, seg);
    seg[id * 2].tag += seg[id].tag;
    seg[id * 2 + 1].tag += seg[id].tag;
    seg[id].tag = 0;
}
int query(int ql, int qr, int left, int right,
    int id, vector<Node>& seg)
{
    if (qr < left || ql > right)
        return 0;
    if (qr >= right && ql <= left)
        return get_val(left, right, id, seg);
    push(left, right, id, seg);
    int mid = left + (right - left) / 2;
    return query(ql, qr, left, mid, id * 2, seg)
        + query(ql, qr, mid + 1, right, id * 2 + 1, seg);
}
void update(int ql, int qr, int val,
    int left, int right, int id, vector<Node>& seg)
{
    if (qr < left || ql > right)
        return;
    if (qr >= right && ql <= left) {
        seg[id].tag += val;
        return;
    }
    push(left, right, id, seg);
    int mid = left + (right - left) / 2;
    update(ql, qr, val, left, mid, id * 2, seg);
    update(ql, qr, val, mid + 1, right, id * 2 + 1, seg);
    pull(left, right, id, seg);
}
void build_tree(vector<Node>& seg, int left, int right, int id,
    vector<int>& v)
{
    if (left == right) {
        seg[id].data = v[left];
        seg[id].tag = 0;
        return;
    }

    int mid = left + (right - left) / 2;
    build_tree(seg, left, mid, id * 2, v);
    build_tree(seg, mid + 1, right, id * 2 + 1, v);
    pull(left, right, id, seg);
}

// #include <iostream>
// using namespace std;

// long long n, q, t, a, b, u, bit[200005];

// void update(int x, int d)
// {
//     while (x <= n) {
//         bit[x] += d;
//         x += x & (-x);
//     }
// }
// long long query(int x)
// {
//     long long ret = 0;
//     while (x) {
//         ret += bit[x];
//         x -= x & (-x);
//     }
//     return ret;
// }

// int main()
// {
//     cin >> n >> q;
//     long long pre = 0;
//     for (int i = 1; i <= n; i++) {
//         cin >> a;
//         update(i, a - pre);
//         pre = a;
//     }
//     for (int i = 0; i < q; i++) {
//         cin >> t;
//         if (t == 1) {
//             cin >> a >> b >> u;
//             update(a, u);
//             update(b + 1, -u);
//         } else {
//             cin >> a;
//             cout << query(a) << "\n";
//         }
//     }
// }