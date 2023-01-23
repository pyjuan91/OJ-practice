#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;

long long solve(int n, vector<int> &a, long long sum) {
    long long res = 1e9 + 5;
    for (int i = 0; i < (1 << n); i++) {
        long long part = 0;
        int num = i;
        for (int j = 0; j < n; j++) {
            if (num & 1) part += a[n - 1 - j];
            num >>= 1;
        }
        res = min(res, llabs(sum - 2 * part));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cout << solve(n, a, sum);
    return 0;
}