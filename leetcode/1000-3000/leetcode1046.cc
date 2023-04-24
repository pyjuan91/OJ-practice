#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int lastStoneWeight(vector<int>& stones) {
			priority_queue<int> pq;
			for (auto stone : stones) pq.push(stone);
			while (pq.size() > 1) {
				auto a = pq.top();
				pq.pop();
				auto b = pq.top();
				pq.pop();
				pq.push(a - b);
			}
			if (pq.empty()) return 0;
			return pq.top();
		}
};
int main() { return 0; }