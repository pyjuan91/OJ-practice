#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000005;
void getArmstrong(vector<int>& armstrong)
{
    for (int i = 1; i < maxn; i++) {
        int sum = 0, tmp = i, digits = 0;
        while (tmp) {
            digits++;
            tmp /= 10;
        }
        tmp = i;
        while (tmp) {
            sum += pow(tmp % 10, digits);
            tmp /= 10;
        }
        if (sum == i)
            armstrong.push_back(i);
    }
}
int main(void)
{
    vector<int> armstrong;
    getArmstrong(armstrong);
    int a, b, none = 1;
    cin >> a >> b;
    for (auto i : armstrong) {
        if (i >= a && i <= b) {
            if (none == 1) {
                cout << i;
                none = 0;
            } else {
                cout << " " << i;
            }
        }
    }
    if (none)
        cout << "none";
    cout << endl;
    return 0;
}