#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, int> positionMap;
class Cat {
public:
    string name;
    int position, age;

    Cat(string& name, int& position, int& age)
    {
        this->name = name;
        this->position = position;
        this->age = age;
    }

    bool operator>(const Cat& b) const
    {
        if (position == b.position) {
            if (position == 5) {
                if (age == b.age) {
                    return name < b.name;
                }
                return age < b.age;
            }
            if (age == b.age) {
                return name < b.name;
            }
            return age > b.age;
        }
        return position < b.position;
    }
};
void helper(vector<string>& res);
void initMap(void);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> res;
    initMap();
    helper(res);
    for (string& str : res) {
        cout << str << "\n";
    }
    return 0;
}
void helper(vector<string>& res)
{
    int n, m;
    string name, position;
    int age;
    while (cin >> n >> m) {
        vector<Cat> v;
        for (int i = 0; i < n; i++) {
            cin >> name >> position >> age;
            Cat c(name, positionMap[position], age);
            v.push_back(c);
        }
        sort(v.begin(), v.end(), greater<Cat>());
        for (int i = 0; i < min(m, (int)v.size()); i++) {
            res.push_back(v[i].name);
        }
    }
}
void initMap(void)
{
    positionMap["elder"] = 1;
    positionMap["nursy"] = 2;
    positionMap["kit"] = 3;
    positionMap["warrior"] = 4;
    positionMap["appentice"] = 5;
    positionMap["medicent"] = 6;
    positionMap["deputy"] = 7;
    positionMap["leader"] = 8;
}