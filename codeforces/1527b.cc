#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

string patty(int n, string& s)
{
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());

    bool is_palindrome = rev_s == s;

    int cost = count(s.begin(), s.end(), '0');
    if(cost == 0)
    {
        return "DRAW";
    }
    if(not is_palindrome)
    {
        return "ALICE";
    }
    if(cost % 2 == 1)
    {
        if(cost == 1)
            return "BOB";
        return "ALICE";
    }
    return "BOB";
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        cout << patty(n, s) << "\n";
    }
    return 0;
}
