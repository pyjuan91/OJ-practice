#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int tar = round((float)sum / n);
    sum = 0;
    for (auto i : v) {
        sum += pow(i - tar, 2);
    }
    cout << sum;
    return 0;
}