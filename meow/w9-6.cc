// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> P;
// class Edge {
// public:
//     int start, end, cost;
//     Edge()
//     {
//         start = end = cost = 0;
//     }
//     Edge(int _start, int _end, int _cost)
//     {
//         start = _start;
//         end = _end;
//         cost = _cost;
//     }
// };
// vector<long long> bellman(vector<Edge>& e, int n, int st, int m)
// {
//     vector<long long> dis(n, 1e18);
//     dis[st] = 0;

//     auto relax = [&](Edge edge) {
//         if (dis[edge.end] > dis[edge.start] + edge.cost) {
//             dis[edge.end] = dis[edge.start] + edge.cost;
//             return true;
//         }
//         return false;
//     };

//     for (int t = 0; t < m; t++) {
//         bool update = false;
//         for (auto& edge : e) {
//             update |= relax(edge);
//         }
//         if (t == m - 1 && update) {
//             return {};
//         }
//     }
//     return dis;
// }
// int main(void)
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(nullptr);
//     // ifstrpen("input.txt");
//     int n, m, a, b, x;
//     cin >> n >> m;

//     vector<Edge> e;
//     for (int i = 0; i < m; i++) {
//         cin >> a >> b >> x;
//         Edge edge(a - 1, b - 1, 0 - x);
//         e.emplace_back(edge);
//     }

//     vector<long long> ans = bellman(e, n, 0, m);
//     if (ans.size() == 0)
//         cout << "-1\n";
//     else
//         cout << 0 - ans[n - 1] << "\n";
//     // for (int i = 0; i < n; i++) {
//     //     cout << ans[i] << " ";
//     // }
//     // cout << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long int
#define pb push_back
#define ar array
#define mp make_pair
#define f(i, n) for (ll i = 0; i < n; i++)
#define inf INT_MAX
#define pll pair<ll, ll>
const ll INF = 1e18;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool checkp2(ll n)
{
    return n && (n - 1);
}

ll power(ll x, ll n, ll mod)
{
    ll po = 1;
    while (n) {
        if (n & 1) {
            po = (po * x) % mod;
        }
        n = n >> 1;
        x = (x * x) % mod;
    }
    return po;
}

bool isPrime(ll x)
{
    if (x < 2)
        return 0;
    for (ll y = 2; y * y <= x; y++) {
        if (x % y == 0) {
            return 0;
        }
    }
    return true;
}

const ll mxn = 3000;
const ll nxn = 5010;
ll n, m;
vector<ar<ll, 3>> adj;
ll d[mxn];
vector<ll> ad[mxn], ad2[mxn];
bool ans;
bool vis[mxn], vis1[mxn];
void dfs1(ll u, ll p = -1)
{
    vis[u] = 1;
    for (ll v : ad[u]) {
        if (v == p)
            continue;
        if (!vis[v])
            dfs1(v, u);
    }
}
void dfs2(ll u, ll p = -1)
{
    vis1[u] = 1;
    for (ll v : ad2[u]) {
        if (v == p)
            continue;
        if (!vis1[v])
            dfs2(v, u);
    }
}

void solve()
{
    // ifstream cin;
    // cin.open("input.txt");
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;

    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj.push_back({ a, b, -c });
        ad[a].push_back(b);
        ad2[b].push_back(a);
    }
    dfs1(0);
    dfs2(n - 1);

    for (ll i = 0; i < n - 1; i++) {
        for (ll j = 0; j < m; j++) {
            ar<ll, 3> k = adj[j];
            if (d[k[0]] + k[2] < d[k[1]])
                d[k[1]] = d[k[0]] + k[2];
        }
    }

    for (ll i = 0; i < m; i++) {
        ar<ll, 3> k = adj[i];
        if (d[k[0]] + k[2] < d[k[1]]) {
            if (vis1[k[0]] && vis[k[0]]) {
                cout << "-1" << endl;
                return;
            }
        }
    }
    // if (n > 1) {
    cout << -d[n - 1] << endl;
    // } else {
    //     cout << "0" << endl;
    // }
    // cin.close();
}
int main()
{
    // init();
    ll t = 1;
    // cin>>t;

    for (ll i = 1; i <= t; i++) {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    
    return 0;
}