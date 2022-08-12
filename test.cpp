#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void printPermutation(int n, vector<int>& v, int cur)
{
    if (cur == n) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            int ok = 1;
            for (auto j : v) {
                if (j == i)
                    ok = 0;
            }
            if (ok) {
                v[cur] = i;
                printPermutation(n, v, cur + 1);
                v[cur] = 0;
            }
        }
    }
}
int main(void)
{
    int n;
    while (cin >> n) {
        vector<int> v(n);
        printPermutation(n, v, 0);
    }
    return 0;
}