#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v[N];
bool vsit[N];

void dfs(int src)
{
    cout << src << endl;
    vsit[src] = true;
    for (int child : v[src])
    {
        if (vsit[child] == false)
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--) 
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vsit, false, sizeof(vsit));
    dfs(0);

    return 0;
}