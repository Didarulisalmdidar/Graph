#include<bits/stdc++.h>
using namespace std;
const int M=200000;
vector<pair<long long,int>>adj[M+5];
vector<long long>D;
void dijkstra(int src,int node)
{
    D.clear();
    D.resize(node+1,LLONG_MAX/2);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,src});
    D[src]=0;
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        int u=p.second;
        long long d=p.first;
        if(d>D[u])
            continue;
        for(auto pr:adj[u])
        {
            int v=pr.second;
            long long next_d=d+pr.first;
            if(next_d<D[v])
            {
                D[v]=next_d;
                pq.push({next_d,v});
            }
        }
    }


}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});

    }
   dijkstra(1,n);
   for(int i=1;i<=n;i++)
    cout<<D[i]<<" ";
}


