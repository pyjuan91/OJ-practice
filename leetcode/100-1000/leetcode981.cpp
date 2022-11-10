#include <iostream>
#include <map>
#include <string>
using namespace std;
class TimeMap {
private:
    using P = pair<int, string>;
    map<string, map<int, string>> mm;

public:
    TimeMap()
    {
        mm.clear();
    }

    void set(string key, string value, int timestamp)
    {
        P p = { timestamp, value };
        if (mm.find(key) == mm.end()) {
            map<int, string> m;
            m[timestamp] = value;
            mm[key] = m;
        } else {
            mm[key].insert({ timestamp, value });
        }
    }

    string get(string key, int timestamp)
    {
        if (mm.count(key) == 0)
            return "";
        int ma = INT32_MIN;
        for (auto iter = mm[key].rbegin(); iter != mm[key].rend(); iter++) {
            if (iter->first <= timestamp) {
                return iter->second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
int main(void) { return 0; }