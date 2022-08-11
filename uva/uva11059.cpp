#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n, kase = 0;
    while (cin >> n) {
        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        long long ans = 0, pro = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pro = 1;
                for (int k = i; k <= j; k++) {
                    pro *= num[k];
                }
                ans = max(ans, pro);
            }
        }
        cout << "Case #" << ++kase << ": The maximum product is " << ans << "." << endl
             << endl;
    }
    return 0;
}