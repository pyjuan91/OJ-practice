#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, a, b, c, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a + b + c > 1)
            res++;
    }
    cout << res;
    return 0;
}