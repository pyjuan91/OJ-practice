#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    int pairSum(ListNode* head)
    {
        int maxSum = INT_MIN;
        stack<int> s;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        while (slow) {
            maxSum = max(maxSum, slow->val + s.top());
            s.pop();
            slow = slow->next;
        }
        return maxSum;
    }
};
int main(void) { return 0; }