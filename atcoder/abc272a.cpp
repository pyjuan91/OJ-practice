#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, sum = 0, e;
    cin >> n;
    while (n--) {
        cin >> e;
        sum += e;
    }
    cout << sum << "\n";
    return 0;
}