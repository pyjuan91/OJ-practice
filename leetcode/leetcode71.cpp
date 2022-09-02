#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
private:
    vector<string> s;

public:
    string simplifyPath(string path)
    {
        // clear the stack
        s.clear();

        int i = 0;
        string str;
        for (;;) {
            str = getDirName(path, i);
            if (str == "")
                break;
            if (str == "..") {
                if (!s.empty())
                    s.pop_back();
            } else if (str == ".") {
                continue;
            } else {
                s.push_back(str);
            }
        }

        str = "";
        for (string& t : s) {
            str += "/" + t;
        }
        if (str == "")
            str = "/";
        return str;
    }

    string getDirName(string path, int& i)
    {
        int start = i;
        while (start < path.length()) {
            if (path[start] != '/')
                break;
            start++;
        }
        i = start;
        while (i < path.length()) {
            if (path[i] == '/')
                break;
            i++;
        }
        if (i == start)
            return "";
        return path.substr(start, i - start);
    }
};
int main(void) { return 0; }