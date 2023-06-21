#include<iostream> 
using namespace std;
const int N = 100;
int map[N][N];
int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 1;i <= m;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            cin >> map[i][j];
        }
    }
    return 0;
}