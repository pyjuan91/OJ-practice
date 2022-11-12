#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        bool first = true;
        ListNode* res = nullptr;
        ListNode* last = nullptr;
        ListNode* cur = head;
        int cnt = 0;
        vector<ListNode*> v;
        while (cur) {
            v.push_back(cur);
            cnt += 1;
            cur = cur->next;

            if (cnt == k) {
                ListNode* cc;
                cc = v.back();
                if (last)
                    last->next = cc;
                if (first) {
                    res = cc;
                    first = false;
                }
                v.pop_back();
                while (!v.empty()) {
                    cc->next = v.back();
                    cc = cc->next;
                    v.pop_back();
                }
                cc->next = cur;
                last = cc;
                cnt = 0;
            }
        }
        return res;
    }
};
int main(void)
{
    return 0;
}