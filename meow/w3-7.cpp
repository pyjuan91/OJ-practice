#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1000005;
int left[maxn], right[maxn], queue[maxn], tail[maxn];
void link(int L, int R)
{
    right[L] = R;
    left[R] = L;
}
int main(void)
{
    int n, m, cmd, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        left[i] = right[i] = -i;
        queue[i] = tail[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &cmd, &a, &b);
        if (cmd == 0) {

            if (left[a] < 0) {
                if (right[a] < 0) {
                    queue[-left[a]] = -1;
                    tail[-left[a]] = -1;
                } else {
                    queue[-left[a]] = right[a];
                    left[right[a]] = left[a];
                }
            } else if (right[a] < 0) {
                right[left[a]] = right[a];
                tail[-right[a]] = left[a];
            } else {
                link(left[a], right[a]);
            }

            int rb = right[b];
            link(b, a);
            if (rb > 0) {
                link(a, rb);
            } else {
                right[a] = rb;
                tail[-rb] = a;
            }

        } else {

            if (queue[a] < 0) {
                continue;
            } else if (queue[b] < 0) {
                queue[b] = queue[a];
                tail[b] = tail[a];
                queue[a] = -1;
                tail[a] = -1;
                left[queue[b]] = -b;
                right[tail[b]] = -b;
            } else {
                link(tail[b], queue[a]);
                right[tail[a]] = -b;
                tail[b] = tail[a];
                queue[a] = -1;
                tail[a] = -1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cur = queue[i];
        printf("#%d:", i);
        while (cur > 0) {
            printf(" %d", cur);
            cur = right[cur];
        }
        printf("\n");
    }
    return 0;
}