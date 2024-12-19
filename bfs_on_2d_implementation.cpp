#include <bits/stdc++.h>
using namespace std;
bool vsit[20][20];
char a[20][20];
int n, m;
int dist[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vsit[si][sj] = true;
    dist[si][sj] = 0;
    while (!q.empty())
    {

        pair<int, int> par = q.front();
        q.pop();
        // cout << par.first << " " << par.second << endl;
        // void bfs(int si, int sj)

            // cout << si << " " << sj << endl;
            // vsit[si][sj] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) == true && vsit[ci][cj] == false)
            {
                q.push({ci, cj});
                vsit[ci][cj] = true;
                dist[ci][cj] = dist[par.first][par.second] + 1;
            }
        }
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
    }
    int si, sj;
    cin >> si >> sj;
    memset(vsit, false, sizeof(vsit));
    memset(dist, -1, sizeof(dist));
    bfs(si, sj);
    cout << dist[2][3];

    return 0;
}