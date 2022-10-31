#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<char> st;
    for (char& c : str) {
        if (c == 'T' && !st.empty() && st.top() == 'S')
            st.pop();
        else
            st.emplace(c);
    }
    cout << st.size() << "\n";
    return 0;
}