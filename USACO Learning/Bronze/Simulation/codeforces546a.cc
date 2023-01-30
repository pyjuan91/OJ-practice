#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    long long k, n, w;
    cin >> k >> n >> w;
    cout << max(w * (w + 1) / 2 * k - n, 0LL);
    return 0;
}