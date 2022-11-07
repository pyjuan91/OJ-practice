#include <iostream>
using namespace std;
int main(void)
{
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    for (int i = p; i <= q; i++) {
        for (int j = r; j <= s; j++) {
            if (i - a == j - b || i - a == b - j)
                cout << '#';
            else
                cout << '.';
        }
        cout << '\n';
    }
    return 0;
}