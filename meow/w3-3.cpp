#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
class myObject {
public:
    int num, ma, order;
    long long sum;
    vector<int> bananaMilk;

    myObject(long long sum, int num, int ma, int order, vector<int>& bananaMilk)
    {
        this->sum = sum;
        this->num = num;
        this->ma = ma;
        this->order = order;
        this->bananaMilk = bananaMilk;
    }

    bool operator<(const myObject& b) const
    {
        if (sum == b.sum) {
            if (ma == b.ma) {
                if (num == b.num) {
                    return order > b.order;
                }
                return num < b.num;
            }
            return ma < b.ma;
        }
        return sum < b.sum;
    }

    bool operator==(const myObject& b) const
    {
        return sum == b.sum && num == b.num
            && ma == b.ma && order == b.order;
    }

    bool operator>(const myObject& b) const
    {
        return !((*this) < b || (*this) == b);
    }
};
int T, N, K;
void input(vector<myObject>& v);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        vector<myObject> v;
        input(v);
        sort(v.begin(), v.end(), greater<myObject>());
        for (auto obj : v) {
            bool first = true;
            for (int& i : obj.bananaMilk) {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << i;
            }
            cout << "\n";
        }
    }
    return 0;
}
void input(vector<myObject>& v)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        int e, ma = INT_MIN;
        long long sum = 0;
        vector<int> bm;
        for (int j = 0; j < K; j++) {
            cin >> e;
            bm.push_back(e);
            sum += (long long)e;
            ma = max(ma, e);
        }
        myObject entry(sum, K, ma, i, bm);
        v.push_back(entry);
    }
}