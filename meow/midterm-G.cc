#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<long long>&, vector<long long>&, long long, long long);
int main(void)
{
#define int long long
#define endl '\n'
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), f(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(f.begin(), f.end());

    int left = -1, right = 1e12;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;

        if (check(a, f, mid, k))
            right = mid;
        else
            left = mid;
    }

    cout << right << endl;

    return 0;
}
bool check(vector<int>& a, vector<int>& f, int guess, int quota)
{
    for (int i = 0; i < a.size(); i++) {
        int remain = guess / f[i];
        if (a[i] > remain) {
            if (quota < a[i] - remain)
                return false;
            quota -= a[i] - remain;
        }
    }
    return true;
}