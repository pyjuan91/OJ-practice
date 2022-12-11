#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> route;
int used[100005];
long long ans[100005];
int n;
void init();
void dijkstra(int syrjala);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, a, b, c;
    cin >> n >> m;
    init();
    while (m--) {
        cin >> a >> b >> c;
        if (route[{ a, b }] == 0) {
            route[{ a, b }] = c;
            route[{ b, a }] = c;
        } else {
            route[{ a, b }] = min(route[{ a, b }], c);
            route[{ b, a }] = min(route[{ b, a }], c);
        }
    }
    // cout << endl;
    // for (auto i : route) {
    //     cout << i.first.first << " " << i.first.second
    //          << " " << i.second << endl;
    // }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << " ";
        std::cout << ans[i];
    }
    std::cout << endl;
    return 0;
}
void init()
{
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
        ans[i] = 1e14 + 5;
    }
}
void dijkstra(int syrjala)
{
    ans[syrjala] = 0;

    for (int i = 1; i <= n; i++) {
        int next = -1;
        long long mi = 1e14 + 5;
        for (int j = 1; j <= n; j++) {
            if (used[j] == 0 && ans[j] < mi) {
                mi = ans[j];
                next = j;
            }
        }
        if (next == -1)
            break;
        used[next] = 1;
        for (int j = 1; j <= n; j++) {
            if (used[j] == 0 && route[{ next, j }]
                && ans[next] + route[{ next, j }] < ans[j]) {
                ans[j] = ans[next] + route[{ next, j }];
            }
        }
    }
}