#include <iostream>

using namespace std;

int main()

{
    int a, b;

    while (cin >> a >> b)

    {
        if (a != b)

        {
            cout << b + 1 << endl;
        }

        if (a == b)

        {
            cout << b << endl;
        }
    }
}