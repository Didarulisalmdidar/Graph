#include<bits/stdc++.h>
using namespace std;
const int MAX=200005;
vector<int>adj[MAX];
vector<int>dist;
void bfs(int src,int n)
{
    dist.clear();
    dist.resize(n+1,MAX/2);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto it:adj[u])
        {
            if(dist[it]==MAX/2){
                q.push(it);
                dist[it]=dist[u]+1;
            }
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
    if(n==1)
    {
        cout<<"0"<<"\n";
        return 0;
    }

    bfs(1,n);
    int mx=0;
    int node;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<dist[i]<<endl;
        if(dist[i]>mx && dist[i]!=MAX/2)
        {
            mx=dist[i];
            node=i;
        }
    }
    //cout<<node<<endl;
    bfs(node,n);
    int diamet=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]>diamet && dist[i]!=MAX/2)
        {
            diamet=dist[i];
        }
    }
    cout<<diamet<<endl;

}
