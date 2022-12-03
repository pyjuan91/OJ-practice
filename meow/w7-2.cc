#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define endl '\n'
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n;
    vector<int> v(1000005, 0);
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x] += 1;
    }
    int mg = 1;
    for (int i = 2; i <= 1000000; i++) {
        int cnt = 0;
        for (int j = i; j <= 1000000; j += i) {
            cnt += v[j];
        }
        if (cnt > 1)
            mg = i;
    }
    cout << mg << endl;
    return 0;
}