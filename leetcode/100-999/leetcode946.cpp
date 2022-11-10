#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        if (pushed.size() != popped.size())
            return false;
        stack<int> s;
        int j = 0;
        for (int i = 0; i < popped.size(); i++) {
            while ((s.empty() || popped[i] != s.top()) && j < pushed.size()) {
                s.push(pushed[j++]);
            }
            if (s.top() == popped[i])
                s.pop();
            else
                return false;
        }
        return true;
    }
};
int main(void) { return 0; }