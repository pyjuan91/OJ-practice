#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int bit;
    Node* next;
    Node(int bit)
    {
        this->bit = bit;
        this->next = nullptr;
    }

    Node& operator=(Node& b)
    {
        this->bit = b.bit;
        this->next = b.next;
        return *this;
    }
};
vector<Node*> res;
int n;
void helper(int now)
{
    if (now == 1) {
        Node* neo = new Node(0);
        res.push_back(neo);
        neo = new Node(1);
        res.push_back(neo);
        return;
    }
    helper(now - 1);
    int sz = res.size();
    vector<Node*> rev(sz);
    for (int i = 0; i < sz; i++) {
        rev[i] = res[sz - 1 - i];
    }
    for (int i = 0; i < sz; i++) {
        Node* z = new Node(0);
        z->next = res[i];
        res[i] = z;

        z = new Node(1);
        z->next = rev[i];
        res.push_back(z);
    }
}
int main(void)
{
    cin >> n;
    helper(n);
    for (int i = 0; i < res.size(); i++) {
        while (res[i] != nullptr) {
            cout << res[i]->bit;
            res[i] = res[i]->next;
        }
        cout << "\n";
    }
    return 0;
}