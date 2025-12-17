#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < n - s.length(); i++)
    {
        cout << "o";
    }
    cout << s << "\n";
    return 0;
}
