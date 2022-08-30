#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<int> diff(gas.size());
        int checker = 0, maxSum = INT_MIN, sum = 0, head;
        for (int i = 0; i < gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
            checker += diff[i];
        }
        if (checker < 0)
            return -1;
        for (int i = 0; i < gas.size(); i++) {
            if (sum > 0) {
                sum += diff[i];
            } else {
                if (diff[i] > 0) {
                    head = i;
                }
                sum = diff[i];
            }
        }
        return head;
    }
};
int main(void) { return 0; }