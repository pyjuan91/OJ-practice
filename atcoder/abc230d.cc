#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool myCmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) {
        return a.second < b.second;
    }
    return a.second < b.second;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, res = 0;
    cin >> n >> d;
    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i].first >> w[i].second;

    sort(w.begin(), w.end(), myCmp);

    for (int i = 0; i < n; i++) {
        res += 1;
        int left = w[i].second, right = w[i].second + d - 1;
        i++;
        while (i < n && w[i].first <= right && w[i].second >= left) {
            i++;
        }
        i--;
    }

    cout << res << "\n";

    return 0;
}