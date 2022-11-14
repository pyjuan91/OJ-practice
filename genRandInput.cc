#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;
int main(void)
{
    fstream fout;
    fout.open("input.txt", ios::out);
    srand((unsigned)time(nullptr));
    // Generate
    int n, m;
    n = rand() % 1000 + 1;
    m = rand() % 1000 + 1;

    const char g[8] = { '#', '.', 'M', '.', '.', '.', '.', '.' };
    int cnta = 0;
    int sx = rand() % n;
    int sy = rand() % m;
    fout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == sx && j == sy)
                fout << 'A';
            else {
                int sel = rand() % 1000;
                if (sel < 1)
                    fout << 'M';
                else if (sel < 2)
                    fout << '#';
                else
                    fout << '.';
            }
        }
        fout << "\n";
    }
}