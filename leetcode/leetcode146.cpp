#include <iostream>
#include <queue>
using namespace std;
struct Node {
    Node *next, *prev;
    int val;

    Node()
    {
        next = prev = nullptr;
        val = 0;
    }

    Node(int n)
    {
        next = prev = nullptr;
        val = n;
    }
};
class LRUCache {
private:
    Node *head = nullptr, *tail = nullptr;
    int hashMap[10005], num = 0, capacity, isInMap[10005] = {};
    Node* nodeMap[10005];

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        for (int i = 0; i < 10005; i++) {
            hashMap[i] = -1;
        }
    }

    int get(int key)
    {
        if (isInMap[key]) {
            moveToTail(nodeMap[key]);
        }
        return hashMap[key];
    }

    void put(int key, int value)
    {
        if (isInMap[key]) {
            hashMap[key] = value;
            moveToTail(nodeMap[key]);
            return;
        }
        if (num == capacity) {
            removeEntry();
        }
        isInMap[key] = 1;
        num += 1;
        hashMap[key] = value;
        Node* neo = new Node(key);
        if (head == nullptr) {
            head = tail = neo;
        } else {
            tail->next = neo;
            neo->prev = tail;

            tail = tail->next;
        }
        nodeMap[key] = neo;
    }

    void removeEntry()
    {
        isInMap[head->val] = 0;
        hashMap[head->val] = -1;
        nodeMap[head->val] = nullptr;
        num -= 1;
        Node* pos = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete pos;
    }

    void moveToTail(Node* node)
    {
        if (node == tail)
            return;
        if (node == head) {
            head = head->next;
            head->prev = nullptr;

            node->next = nullptr;
            node->prev = tail;

            tail->next = node;
            tail = tail->next;
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = nullptr;
        node->prev = tail;

        tail->next = node;
        tail = tail->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(void) { return 0; }