#include "iostream"

using namespace std;

long long solve(int n) {
    long long sq = 1LL * n * n;
    long long res = sq * (sq - 1);
    long long twoByThree = 1LL * (n - 2) * (n - 1);
    res = res / 2 - twoByThree * 2 * 2;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cout << solve(i) << "\n";
    return 0;
}