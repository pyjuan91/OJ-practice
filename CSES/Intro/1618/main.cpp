#include <cmath>
#include "iostream"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i < 13; i++)
        ans += n / (int) pow(5, i);
    cout << ans;
    return 0;
}