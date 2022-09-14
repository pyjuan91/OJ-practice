#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    long long bx, by, lx, ly, rx, ry, res = 0;
    cin >> bx >> by >> lx >> ly >> rx >> ry;
    if (bx < lx || bx > rx)
        res += min(labs(bx - lx), labs(bx - rx));
    if (by < ly || by > ry)
        res += min(labs(by - ly), labs(by - ry));
    cout << res << "\n";
    return 0;
}