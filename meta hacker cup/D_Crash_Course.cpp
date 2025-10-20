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
    if (s.back() == 'A')
    {
        return "Alice";
    }
    deque<char> dq(s.begin(), s.end());
    while (!dq.empty() && dq.front() == 'B')
    {
        dq.pop_front();
    }
    int count_A = count(dq.begin(), dq.end(), 'A');
    int count_B = dq.size() - count_A;
    if (count_A > count_B)
    {
        return "Alice";
    }
    return "Bob";
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    string s;
    cin >> t;
    for (int kase = 1; kase <= t; kase++)
    {
        cin >> n >> s;
        cout << "Case #" << kase << ": " << patty(n, s) << "\n";
    }
    return 0;
}
