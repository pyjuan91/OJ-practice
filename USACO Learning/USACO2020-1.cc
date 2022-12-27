#include <algorithm>
#include <iostream>
using namespace std;
int main(void)
{
    int seq[7], a, b, c, ab, bc, ac, abc;
    for (int i = 0; i < 7; i++)
        cin >> seq[i];
    sort(seq, seq + 7);
    a = seq[0];
    b = seq[1];
    abc = seq[6];
    c = abc - a - b;
    cout << a << " " << b << " " << c;
    return 0;
}