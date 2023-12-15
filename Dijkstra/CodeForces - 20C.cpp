#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=100010;
vector<pair<long long,int>>adj[M+5];
vector<long long>D;
vector<int>path;
int parent[M+5];
void getShortestPath(int src,int node)
{
    for(int i=1;i<=node;i++)
        parent[i]=i;
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
                parent[v]=u;
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
        adj[b].push_back({c,a});

    }
   getShortestPath(1,n);
   if(parent[n]==n)
    cout<<"-1"<<endl;
   else
   {
       //findPath(n);
       int tmp=n;
       while(n!=1)
       {
           path.push_back(parent[n]);
           n=parent[n];
       }
       reverse(path.begin(),path.end());
       for(auto it:path)
        cout<<it<<" ";
        cout<<tmp<<endl;
   }



}



