#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int a, b, x, y;
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    cin >> a >> b >> x >> y;
    cout << min({ abs(a - b), abs(a - x) + abs(y - b),
        abs(a - y) + abs(x - b) });
    return 0;
}