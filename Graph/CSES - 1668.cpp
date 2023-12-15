#include<bits/stdc++.h>
using namespace std;
const int MAX=200000;
vector<int>adj[MAX+5];
bool visited[MAX+5];
int teamNo[MAX+5];
bool flag;
void bfs(int u,int team)
{
    queue<int>q;
    q.push(u);
    visited[u]=true;
    teamNo[u]=team;
   while(!q.empty())
   {
       int p=q.front();
       q.pop();
       for(auto it:adj[p])
       {
           if(visited[it]==true)
           {
               if(teamNo[it]==teamNo[p])
               {
                   flag=true;
                   return;
               }
           }
           else{
           teamNo[it]=teamNo[p]^1;
           //cout<<it<<" "<<teamNo[it]<<endl;
           q.push(it);
           visited[it]=true;
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
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bfs(i,0);
        }
    }
    if(flag)
        cout<<"IMPOSSIBLE"<<endl;
    else{

        for(int i=1;i<=n;i++)
            cout<<teamNo[i]+1<<" ";
        puts("");
    }
}

