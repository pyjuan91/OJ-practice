#include <iostream>
#include <string>
using namespace std;
string solve(int n, int m)
{
    if ((n % 2) ^ (m % 2))
        return "Burenka";
    return "Tonya";
}
int main(void)
{
    int n, m, t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << solve(n, m) << "\n";
    }
    return 0;
}