#include<bits/stdc++.h>
using namespace std;
const int MAX=200000;
vector<int>adj[MAX+5];
bool vis[MAX+5];
bool visited[MAX+5];
long long sumd[MAX+5];
long long subTree[MAX+5];
void dfs(int u,int d)
{
    sumd[1]+=d;
    subTree[u]=1;
    vis[u]=1;
    for(auto it:adj[u])
    {
        if(!vis[it])
        {
            dfs(it,d+1);
            //cout<<u<<" "<<it<<" "<<subc[u]<<" "<<subc[it]<<endl;
            subTree[u]+=subTree[it];
        }
    }
}
void distSum(int u,int n)
{
    visited[u]=1;

    for(auto it:adj[u])
    {
        if(!visited[it])
        {
            sumd[it]=sumd[u]+n-(2*subTree[it]);
            distSum(it,n);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    distSum(1,n);

//    for(int i=1;i<=n;i++)
//        cout<<subTree[i]<<endl;

     for(int i=1;i<=n;i++)
        cout<<sumd[i]<<" ";
     cout<<"\n";

}


