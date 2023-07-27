#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int hIndex(vector<int>& citations) {
			int left = 0, right = citations.size()+1;

            auto check = [&](int mid) {
                int cnt = 0;
                for (auto c : citations) {
                    if (c >= mid) cnt++;
                }
                return cnt >= mid;
            };

            while(left + 1 < right) {
                int mid = (left + right) / 2;
                if (check(mid)) left = mid;
                else right = mid;
            }

            return left;
		}
};
int main() { return 0; }