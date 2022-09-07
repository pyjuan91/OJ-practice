#include <iostream>
using namespace std;
class MyTime {
public:
    int h, m;
    MyTime(int h, int m)
    {
        this->h = h;
        this->m = m;
    }
    bool operator<(const MyTime& b) const
    {
        if (h == b.h)
            return m < b.m;
        return h < b.h;
    }
    void operator=(const MyTime& b)
    {
        this->h = b.h;
        this->m = b.m;
    }
    MyTime operator-(const MyTime& b)
    {
        MyTime res(h, m);
        int carry = 0;
        res.m -= b.m;
        if (res.m < 0) {
            carry = -1;
            res.m += 60;
        }
        res.h = res.h - b.h + carry;
        if (res.h < 0) {
            res.h += 24;
        }
        return res;
    }
};
int main(void)
{
    int t, n, h, m;
    cin >> t;
    while (t--) {
        cin >> n >> h >> m;
        MyTime now(h, m), min(23, 59);
        while (n--) {
            cin >> h >> m;
            MyTime compare(h, m);
            if (compare - now < min) {
                min = compare - now;
            }
        }
        cout << min.h << " " << min.m << endl;
    }
    return 0;
}