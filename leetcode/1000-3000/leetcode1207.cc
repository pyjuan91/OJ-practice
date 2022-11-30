#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (int& i : arr) {
            if (m.find(i) == m.end())
                m[i] = 1;
            else
                m[i] += 1;
        }
        for (auto i : m) {
            if (s.find(i.second) != s.end())
                return false;
            s.insert(i.second);
        }
        return true;
    }
};
int main(void) { return 0; }