#include <iostream>
using namespace std;
int main(void)
{
    int n, ans[3], entry;
    while (cin >> n) {
        ans[0] = ans[1] = ans[2] = 0;
        while (n--) {
            cin >> entry;
            ans[entry % 3]++;
        }
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    return 0;
}