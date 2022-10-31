#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        p.push_back(p1 + p2 + p3);
    }
    vector<int> sorted = p;
    sort(sorted.begin(), sorted.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (p[i] + 300 >= sorted[k - 1])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}