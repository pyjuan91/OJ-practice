#include <iostream>
using namespace std;
int main(void)
{
    long long a, b, tmp;
    cin >> a >> b;
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b % a != 0) {
        b = b % a;
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
    }
    cout << a << endl;
    return 0;
}