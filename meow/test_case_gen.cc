#include <bits/stdc++.h>
using namespace std;
double rd()
{
    return (double)rand() / RAND_MAX;
}
int main(void)
{
    srand(time(nullptr));
    ofstream cout;
    cout.open("input.txt");
    int n = 1 + round(2499 * rd());
    int m = 1 + round(4999 * rd());
    cout << n << " " << m << "\n";
    for (int i = 0; i < m; i++) {
        int a = 1 + round((n - 1) * rd());
        int b = 1 + round((n - 1) * rd());
        long long x = -1e9 + (2 * 1e9) * rd();
        cout << a << " " << b << " " << x << "\n";
    }

    // cout << "test" << endl;
    cout.close();
    return 0;
}