#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    int sz;
    vector<int> merge;

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        merge.clear();
        sz = 0;

        int i1 = 0, i2 = 0, m = nums1.size(), n = nums2.size(),
            even = 0, mid = (m + n) / 2;
        if ((m + n) % 2 == 0) {
            even = 1;
        }
        while (sz <= mid + 1 && i1 < m && i2 < n) {
            if (nums1[i1] < nums2[i2]) {
                merge.push_back(nums1[i1]);
                i1 += 1;
            } else {
                merge.push_back(nums2[i2]);
                i2 += 1;
            }
            sz += 1;
        }
        if (sz <= mid + 1) {
            while (i1 < m && sz <= mid + 1) {
                merge.push_back(nums1[i1]);
                i1 += 1;
                sz += 1;
            }
            while (i2 < n && sz <= mid + 1) {
                merge.push_back(nums2[i2]);
                i2 += 1;
                sz += 1;
            }
        }
        if (even) {
            return (double)(merge[mid - 1] + merge[mid]) / 2.0;
        }
        return (double)merge[mid];
    }
};
int main(void) { return 0; }