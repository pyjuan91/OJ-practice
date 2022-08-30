#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string> v;
        int cnt = 1;
        for (int& i : target) {
            while (cnt < i) {
                cnt++;
                v.push_back("Push");
                v.push_back("Pop");
            }
            v.push_back("Push");
            cnt++;
        }
        return v;
    }
};
int main(void) { return 0; }