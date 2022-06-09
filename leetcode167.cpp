#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    set<int> s;
    for (auto i : numbers)
      s.insert(i);
    int sz = s.size();
    int nz = numbers.size();
    for (auto i : s) {
      if (s.count(target - i)) {
        for (int j = 0; j < nz; j++)
          if (numbers[j] == i) {
            ans.push_back(j + 1);
            break;
          }
        for (int j = nz - 1; j >= 0; j--)
          if (numbers[j] == target - i) {
            ans.push_back(j + 1);
            break;
          }
        break;
      }
    }
    return ans;
  }
};
/*
int i =0,j = numbers.size()-1;

        while(i<j){
            int k = numbers[i]+numbers[j];

            if(k==target){
               vector<int> ans{i+1,j+1};
              return ans;
            }

            if(k<target){

                i++;
                continue;
            }

            if(k>target){
                j--;
                continue;
            }
        }

        return numbers;    // won't be reached due to constraints
*/
int main(void) { return 0; }