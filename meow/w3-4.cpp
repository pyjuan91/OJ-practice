#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class ListNode {
public:
    char c;
    ListNode *prev, *next;

    ListNode()
    {
        c = ' ';
        prev = next = nullptr;
    }

    ListNode(char c)
    {
        this->c = c;
        prev = next = nullptr;
    }

    ListNode(char c, ListNode* prev, ListNode* next)
    {
        this->c = c;
        this->prev = prev;
        this->next = next;
    }
};

void solve(string& str)
{
    ListNode* head = new ListNode();
    ListNode* tail = new ListNode();
    head->next = tail;
    tail->prev = head;
    ListNode* cur = head;

    for (char& c : str) {
        if (c == '[')
            cur = head;
        else if (c == ']')
            cur = tail->prev;
        else {
            ListNode* neo = new ListNode(c);
            // prev two direction
            neo->prev = cur;
            neo->next = cur->next;
            cur->next->prev = neo;
            cur->next = neo;

            // move on
            cur = cur->next;
        }
    }

    cur = head;
    while (head->next != tail) {
        cout << head->next->c;
        head = head->next;
    }
    cout << "\n";
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    while (cin >> str) {
        solve(str);
    }
    return 0;
}