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

    int n;
    cin >> n;
    vector<vector<char>> a(3, vector<char>(n));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (j != n - 1)
            {
                getchar();
            }
        }
    }
    // debug(a);
    int col = 0;
    for (;;)
    {
        while (a[0][col] == '.' and a[1][col] == '.' and a[2][col] == '.')
            col++;
        if (col >= n)
            break;
        if (a[0][col] == '#')
        {
            col++;
            cout << "#";
        }
        if (col >= n)
            break;
        if (a[0][col] == '*' or a[1][col] == '*' or a[2][col] == '*')
        {
            int cnt = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = col; j < col + 3; j++)
                {
                    cnt += a[i][j] == '*';
                }
            }

            if (cnt == 6)
                cout << "A";
            else if (cnt == 8)
                cout << "O";
            else if (cnt == 9)
                cout << "E";
            else // cnt == 7
            {
                if (a[0][col + 1] == '*')
                    cout << "I";
                else
                    cout << "U";
            }
            col += 3;
            // debug(cnt, col);
        }
        if (col >= n)
            break;
        // debug(cnt, col);
    }
    return 0;
}
