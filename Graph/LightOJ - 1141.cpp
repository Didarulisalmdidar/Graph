#include<bits/stdc++.h>
using namespace std;
const int MAX=7000;
vector<int>pf[MAX+5];
vector<int>dist;
bool mark[MAX+5];
void primeFactor()
{
    for(int i=2;i<=MAX;i++)
    {
        if(!mark[i])
        {
            for(int j=i+i;j<=MAX;j+=i)
            {
                mark[j]=1;
                pf[j].push_back(i);
            }
        }
    }
}
int bfs(int src,int dest)
{
    dist.clear();
    dist.resize(dest+5,INT_MAX/2);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u>=dest)
            break;
        for(auto it:pf[u])
        {
            int v=it+u;
            if(dist[v]==INT_MAX/2 && v<=dest)
            {
                dist[v]=dist[u]+1;
                //cout<<v<<" "<<dist[v]<<endl;
                q.push(v);
            }

        }
    }
    if(dist[dest]>dest)
        return -1;
    else
        return dist[dest];

}
int main()
{
    primeFactor();
    int t;
    cin>>t;
    int tc=1;
    while(t--)
    {
        int src,dest;
        cin>>src>>dest;
        cout<<"Case "<<tc<<": "<<bfs(src,dest)<<endl;
        tc++;
    }
}

