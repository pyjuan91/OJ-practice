#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int k;
    while (cin >> k) {
        vector<int> v;
        for (int i = k + 1; i <= 2 * k; i++) {
            if (((i * k) % (i - k)) == 0) {
                v.push_back(i);
            }
        }
        cout << v.size() << endl;
        for (auto i : v) {
            cout << "1/" << k << " = "
                 << "1/" << i * k / (i - k) << " + "
                 << "1/" << i << endl;
        }
    }
    return 0;
}