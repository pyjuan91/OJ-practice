#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct STR {
    string s;
    STR(string _s) { s = _s; }
    bool operator<(const STR& b) const
    {
        if (s.length() == b.s.length())
            return s < b.s;
        return s.length() < b.s.length();
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<STR> pos, neg;
        string num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            if (num[0] == '-') {
                num = num.substr(1);
                STR str(num);
                neg.emplace_back(str);
            } else {
                STR str(num);
                pos.emplace_back(str);
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.rbegin(), neg.rend());

        for (auto i : neg)
            cout << "-" << i.s << "\n";

        for (auto i : pos)
            cout << i.s << "\n";
    }
    return 0;
}