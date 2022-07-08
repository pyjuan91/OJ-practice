#include <cmath>
#include <iostream>
using namespace std;
int main(void)
{
    int n;
    while (cin >> n) {
        cout << n * (n * n + 5) / 6 + 1 << endl;
    }
    return 0;
}