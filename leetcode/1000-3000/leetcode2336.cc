#include <bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet {
	public:
		int smallest;
		priority_queue<int, vector<int>, greater<int>> front;
		SmallestInfiniteSet() {
			smallest = 1;
			while (!front.empty()) front.pop();
		}

		int popSmallest() {
			if (!front.empty()) {
				auto res = front.top();
				front.pop();
				while (!front.empty() && front.top() == res)
					front.pop();
				return res;
			}
			smallest += 1;
			return smallest - 1;
		}

		void addBack(int num) {
			if (num >= smallest) return;
			front.push(num);
		}
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
int main() { return 0; }