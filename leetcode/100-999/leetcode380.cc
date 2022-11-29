#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>
using namespace std;
class RandomizedSet {
public:
    set<int> s;
    RandomizedSet()
    {
        s.clear();
        srand(time(nullptr));
    }

    bool insert(int val)
    {
        if (s.find(val) == s.end()) {
            s.insert(val);
            return true;
        }
        return false;
    }

    bool remove(int val)
    {
        if (s.find(val) == s.end()) {
            return false;
        }
        s.erase(val);
        return true;
    }

    int getRandom()
    {
        int rd = rand() % s.size();
        auto it = s.begin();
        while (rd) {
            it++;
            rd--;
        }
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main(void) { return 0; }