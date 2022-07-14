#include <iostream>
using namespace std;
int main(void)
{
    long long n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        switch (a) {
        case 1:
            cout << b + c << endl;
            break;
        case 2:
            cout << b - c << endl;
            break;
        case 3:
            cout << b * c << endl;
            break;
        default:
            cout << b / c << endl;
            break;
        }
    }
    return 0;
}