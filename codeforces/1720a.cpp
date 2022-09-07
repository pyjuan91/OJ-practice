#include <algorithm>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int solve(int& a, int& b, int& c, int& d)
{
    long long AproD = (long long)a * d, BproC = (long long)b * c;
    if (AproD == BproC)
        return 0;
    if (a == 0 || c == 0)
        return 1;
    if ((AproD % BproC == 0) || (BproC % AproD == 0))
        return 1;
    return 2;
}

int main(void)
{
    int t, a, b, c, d;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << "\n";
    }

    return 0;
}