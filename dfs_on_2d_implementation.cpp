#include <bits/stdc++.h>
using namespace std;
char a[20][20];
bool vsit[20][20];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vsit[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && vsit[ci][cj] == false)
        {
            dfs(ci, cj);
        }
        // cout << ci << " " << cj << endl;
        // cout << d[i].first << " " << d[i].second << endl;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << a[i][j];
        //     }
        //     cout << endl;
        // }
    }
    int si, sj;
    cin >> si >> sj;
    memset(vsit, false, sizeof(vsit));
    dfs(si, sj);

    return 0;
}