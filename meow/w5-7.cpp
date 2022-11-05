#include <algorithm>
#include <cstdio>
#include <deque>
#include <stack>
using namespace std;
int a[2000005];
int main(void)
{
    int n, k, start;
    start = 0;
    deque<int> dq;

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    bool first = true;
    for (int end = 0; end < n + k - 1; end++) {

        while (!dq.empty() && a[dq.back() % n] < a[end % n]) {
            dq.pop_back();
        }
        dq.push_back(end);

        if (start > dq.front()) {
            dq.pop_front();
        }

        if (end + 1 >= k) {
            if (first)
                first = false;
            else
                printf(" ");
            printf("%d", a[dq.front() % n]);
            start += 1;
        }
    }

    printf("\n");

    return 0;
}