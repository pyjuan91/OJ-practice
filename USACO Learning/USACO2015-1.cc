#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int a, b, c, d;
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if ((c < a && d < a) || (c > b && d > b))
        cout << d - c + b - a;
    else
        cout << max({ a, b, c, d }) - min({ a, b, c, d });
    return 0;
}