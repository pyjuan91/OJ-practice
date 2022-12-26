#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct Item {
    ll sum, MCS;
    ll prefix_max, postfix_max;

    Item(ll sum = 0)
        : sum(sum)
        , MCS(max(sum, 0LL))
        , prefix_max(MCS)
        , postfix_max(MCS)
    {
    }

    friend Item operator+(const Item& l, const Item& r)
    {
        Item res(l.sum + r.sum);
        res.MCS = max({ l.MCS, r.MCS, l.postfix_max + r.prefix_max });
        res.prefix_max = max(l.prefix_max, l.sum + r.prefix_max);
        res.postfix_max = max(r.postfix_max, r.sum + l.postfix_max);
        return res;
    }
};

void pull(ll, vector<Item>&);
void build(ll, ll, ll, vector<Item>&, vector<ll>&);
Item query(ll, ll, ll, ll, ll, vector<Item>&);
void update(ll, ll, ll, ll, ll, vector<Item>&);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#define int long long
    int n, m, pos, val;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<Item> seg(4 * n);
    build(1, n, 1, seg, a);
    while (m--) {
        cin >> pos >> val;
        update(pos, val, 1, n, 1, seg);
        cout << query(1, n, 1, n, 1, seg).MCS << "\n";
    }
    return 0;
}

void pull(int id, vector<Item>& seg)
{
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void build(int left, int right, int id, vector<Item>& seg, vector<int>& a)
{
    if (left == right) {
        seg[id] = Item(a[left]);
        return;
    }
    int mid = left + (right - left) / 2;
    build(left, mid, id * 2, seg, a);
    build(mid + 1, right, id * 2 + 1, seg, a);
    pull(id, seg);
}

Item query(int ql, int qr, int left, int right, int id,
    vector<Item>& seg)
{
    if (qr < left || ql > right) {
        return Item(0);
    }

    if (qr >= right && ql <= left) {
        return seg[id];
    }

    int mid = left + (right - left) / 2;
    return query(ql, qr, left, mid, id * 2, seg)
        + query(ql, qr, mid + 1, right, id * 2 + 1, seg);
}

void update(int pos, int val, int left, int right,
    int id, vector<Item>& seg)
{
    if (pos < left || pos > right)
        return;
    if (left == right) {
        seg[id] = val;
        return;
    }
    int mid = left + (right - left) / 2;
    update(pos, val, left, mid, id * 2, seg);
    update(pos, val, mid + 1, right, id * 2 + 1, seg);
    pull(id, seg);
}