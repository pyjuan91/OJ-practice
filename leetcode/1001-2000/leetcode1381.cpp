#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node *next, *prev;
    Node()
    {
        val = 0;
        next = prev = nullptr;
    }

    Node(int val)
    {
        this->val = val;
        next = prev = nullptr;
    }
};
class CustomStack {
private:
    int maxSize, size;
    Node *head, *tail;

public:
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
        this->size = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }

    void push(int x)
    {
        if (size == maxSize)
            return;
        Node* neo = new Node(x);

        neo->prev = tail->prev;
        tail->prev->next = neo;

        neo->next = tail;
        tail->prev = neo;

        size++;
    }

    int pop()
    {
        if (size == 0)
            return -1;
        Node* del = tail->prev;
        int res = del->val;
        del->prev->next = tail;
        tail->prev = del->prev;
        delete del;
        return res;
    }

    void increment(int k, int val)
    {
        Node* cur = head;
        while (cur->next != tail && k) {
            cur = cur->next;
            cur->val += val;
            k--;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
int main(void) { return 0; }