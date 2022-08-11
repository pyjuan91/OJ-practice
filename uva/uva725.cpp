#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool check(int i, int dividor)
{
    int num[10] = {};
    if (i < 10000)
        num[0]++;
    while (i) {
        num[i % 10]++;
        i /= 10;
    }
    while (dividor) {
        num[dividor % 10]++;
        dividor /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (num[i] != 1) {
            return false;
        }
    }
    return true;
}
int main(void)
{
    int n, hasSolution, first = 1;
    while (cin >> n && n != 0) {
        if (first)
            first = 0;
        else
            cout << endl;
        hasSolution = 0;
        for (int i = 1234; i <= 87654; i++) {
            int dividor = i * n;
            if (i < 10000 && dividor < 10000)
                continue;
            if (i >= 10000 && dividor >= 100000)
                break;
            if (check(i, dividor)) {
                hasSolution = 1;
                cout << dividor << " / " << ((i < 10000) ? "0" : "") << i << " = " << n << endl;
            }
        }
        if (hasSolution == 0) {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }
    return 0;
}