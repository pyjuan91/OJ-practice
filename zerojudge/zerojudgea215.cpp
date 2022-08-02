#include <iostream>
using namespace std;
int main(void)
{
    int n, m, num, sum;
    while (cin >> n >> m) {
        num = 1, sum = n++;
        while (sum <= m) {
            num++;
            sum += n++;
        }
        cout << num << endl;
    }
    return 0;
}