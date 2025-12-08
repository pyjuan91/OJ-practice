#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n, vector<int>& a)
{
    int num = 1;
    bool ok = true;
    vector<int> res;
    unordered_map<int, int> ideal, real;
    for(const auto& x : a)
    {
        if(ideal.count(x))
        {
            int tnum = ideal[x];
            if(real[tnum] < x)
            {
                res.push_back(tnum);
                real[tnum]++;
            }
            else
            {
                ideal[x] = num;
                res.push_back(num);
                real[num] = 1;
                num++;
            }
        }
        else
        {
            ideal[x] = num;
            res.push_back(num);
            real[num] = 1;
            num++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(real[res[i]] != a[i])
        {
            cout << "-1\n";
            return;
        }
    }
    for(const auto& x : res)
        cout << x << " ";
    cout << "\n";
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> a(n);
        for(auto& x : a)
            cin >> x;
        patty(n, a);
    }
    return 0;
}
