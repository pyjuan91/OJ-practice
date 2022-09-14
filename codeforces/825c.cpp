#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    long long n, k, j, res = 0;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (j = 0; j < n; j++) {
        while (v[j] > 2 * k) {
            res++;
            k *= 2;
        }
        k = max(k, v[j]);
    }
    cout << res << endl;
    return 0;
}