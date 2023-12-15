#include<bits/stdc++.h>
using namespace std;
const int MAX=200000;
vector<int>adj[MAX+5];
bool visited[MAX+5];
void dfs(int u)
{
    visited[u]=true;
    for(auto it:adj[u])
    {
        if(!visited[it])
            dfs(it);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>road;
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            road.push_back(i);
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;

    for(int i=0; i<road.size()-1; i++)
        cout<<road[i]<<" "<<road[i+1]<<endl;
}

