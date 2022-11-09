#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class StockSpanner {
public:
    vector<int> p;
    vector<int> r;

    StockSpanner()
    {
        p.clear();
        r.clear();
    }

    int next(int price)
    {
        int res = 0;
        while (!p.empty() && p.back() <= price) {
            res += r.back();
            p.pop_back();
            r.pop_back();
        }
        res += 1;
        p.push_back(price);
        r.push_back(res);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
int main(void) { return 0; }