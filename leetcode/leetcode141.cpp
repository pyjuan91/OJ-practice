#include <iostream>
#include <unordered_set>
#include <algorithm>
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
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> s;
        while(head)
        {
            if(s.find(head) == s.end())
                s.insert(head);
            else return true;
            head = head->next;
        }
        return false;
    }
};

int main(void)
{
}