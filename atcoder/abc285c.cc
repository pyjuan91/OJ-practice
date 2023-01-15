#include <bits/stdc++.h>
using namespace std;
int main(void) {
    string s;
    cin >> s;
    long long ans = 0;
    for (auto c : s) {
        ans *= 26;
        ans += (c - 'A') + 1;
    }
    cout << ans;
    return 0;
}