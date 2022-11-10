#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int> &nums) {
    int sz = nums.size(), sum = 0;
    int ideaSum = sz * (sz + 1) / 2;
    for (auto i : nums) {
      sum += i;
    }
    return ideaSum - sum;
  }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};
int main(void) {
    int num = 4;
    num ^= 2;
    cout << num << endl;
}