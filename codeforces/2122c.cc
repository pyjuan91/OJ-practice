#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
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
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> x_cords, y_cords;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            x_cords.push_back(make_pair(x, i));
            y_cords.push_back(make_pair(y, i));
        }

        sort(x_cords.begin(), x_cords.end());
        sort(y_cords.begin(), y_cords.end());

        vector<bool> x_greater(n, true), y_greater(n, true);
        for (int i = 0; i < n / 2; i++)
        {
            x_greater[x_cords[i].second] = false;
            y_greater[y_cords[i].second] = false;
        }

        vector<int> A, B, C, D;
        for (int i = 0; i < n; i++)
        {
            if (x_greater[i] && y_greater[i])
                A.push_back(i + 1);
            else if (x_greater[i] && !y_greater[i])
                B.push_back(i + 1);
            else if (!x_greater[i] && y_greater[i])
                C.push_back(i + 1);
            else
                D.push_back(i + 1);
        }
        debug(A, B, C, D);
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " " << D[i] << "\n";
        }
        for (int i = 0; i < B.size(); i++)
        {
            cout << B[i] << " " << C[i] << "\n";
        }
    }
    return 0;
}
