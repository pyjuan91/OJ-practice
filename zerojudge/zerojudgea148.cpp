#include <iostream>
using namespace std;
int main(void)
{
    int n, sum, sc;
    while (cin >> n) {
        sum = 0;
        while (n--) {
            cin >> sc;
            sum += sc - 59;
        }
        if (sum > 0) {
            cout << "no\n";
        } else {
            cout << "yes\n";
        }
    }
    return 0;
}