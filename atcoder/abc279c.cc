#include <bits/stdc++.h>

#include <cstdio>
using namespace std;
int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(m, vector<char>(n));
    vector<vector<char>> t(m, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> s[j][i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> t[j][i];
    vector<string> ts, tt;
    for (int i = 0; i < m; i++) {
        ts.push_back({s[i].begin(), s[i].end()});
        tt.push_back({t[i].begin(), t[i].end()});
    }
    sort(ts.begin(), ts.end());
    sort(tt.begin(), tt.end());
    char Y[] = "Yes";
    char N[] = "No";
    printf("%s", ts == tt ? Y : N);
    return 0;
}