#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head)
    {
        ListNode* pos = head;
        int nodeNum = 0;
        while (pos) {
            nodeNum++;
            pos = pos->next;
        }
        pos = head;
        stack<int> s;
        for (int i = 0; i < nodeNum / 2; i++) {
            s.push(pos->val);
            pos = pos->next;
        }
        if (nodeNum == 0) {
            return false;
        } else {
            if (nodeNum % 2)
                pos = pos->next;
            while (pos) {
                if (pos->val != s.top())
                    return false;
                pos = pos->next;
                s.pop();
            }
        }
        return true;
    }
};
int main(void)
{
    return 0;
}