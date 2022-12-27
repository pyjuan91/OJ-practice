#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int before[4], after[4], promotes[4] ={};
    for (int i = 0; i < 4; i++)
        cin >> before[i] >> after[i];
    for (int i = 3; i >=1; i--) {
        if (after[i] > before[i]) {
            promotes[i] = after[i] - before[i];
            after[i - 1] += promotes[i];
        }
    }
    printf("%d\n%d\n%d\n", promotes[1], promotes[2], promotes[3]);
    return 0;
}