#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef struct node {
    int val, num;
    bool operator<(const node& b) const
    {
        return num < b.num;
    }
    bool operator>(const node& b) const
    {
        return num > b.num;
    }
} Node;
class Solution {
private:
    vector<Node> v;

public:
    int minSetSize(vector<int>& arr)
    {
        v.clear();
        v.resize(100005);
        for (auto i : arr) {
            Node node;
            node.val = i, node.num = v[i].num + 1;
            v[i] = node;
        }
        sort(v.begin(), v.end(), greater<Node>());
        int ans = 0, sum = 0;
        for (int i = 0; i < 100005; i++) {
            ans++;
            sum += v[i].num;
            if (sum >= arr.size() / 2)
                break;
        }
        return ans;
    }
};
int main(void)
{
    Solution s;
    vector<int> arr;
    int x;
    while (cin >> x && x != -1) {
        arr.push_back(x);
    }
    s.minSetSize(arr);
    return 0;
}