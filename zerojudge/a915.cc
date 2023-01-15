#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class P {
public:
    int x, y;
    P() { x = y = 0; }
    P(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    bool operator<(const P& b) const
    {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
};

int main(void)
{
    int n, x, y;
    cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i.x << " " << i.y << "\n";
    return 0;
}