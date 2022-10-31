#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
class wall {
public:
    int height, index;
    wall(int height, int index)
    {
        this->height = height;
        this->index = index;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h;
    cin >> n;
    stack<wall> st;
    wall o(0, 0);
    st.push(o);

    for (int i = 1; i <= n; i++) {
        cin >> h;
        while (st.top().height >= h) {
            st.pop();
        }
        if (i > 1)
            cout << " ";
        cout << st.top().index;
        wall w(h, i);
        st.push(w);
    }
    return 0;
}