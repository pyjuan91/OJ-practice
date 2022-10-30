#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> prefix(n);
    prefix[0] = (long long)a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = (long long)a[i] + prefix[i - 1];
    }

    map<long long, long long> record;
    long long ans = 0;
    long long pref = 0;
    for (int i = 0; i < n; i++) {
        if (prefix[i] == (long long)s)
            ans++;
        if (record.find(prefix[i] - (long long)s) != record.end())
            ans += record[prefix[i] - (long long)s];

        if (record.find(prefix[i]) == record.end())
            record[prefix[i]] = 1;
        else
            record[prefix[i]] += 1;
    }

    cout << ans << "\n";
    return 0;
}