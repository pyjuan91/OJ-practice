#include <iostream>
#include <set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode *> s;
        while(headA)
        {
            s.insert(headA);
            headA = headA->next;
        }
        if(s.empty()) return nullptr;
        while(headB)
        {
            if(s.find(headB) != s.end())
            return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
int main(void)
{
    return 0;
}