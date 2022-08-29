#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int first, second;
        first = edges[0][0], second = edges[0][1];
        if (first == edges[1][0] || first == edges[1][1])
            return first;
        return second;
    }
};
int main(void) { return 0; }