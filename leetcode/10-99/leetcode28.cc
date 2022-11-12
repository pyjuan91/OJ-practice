#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};
int main(void) { return 0; }