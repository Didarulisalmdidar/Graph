#include<bits/stdc++.h>
using namespace std;
#define left st, (st+en)/2, nd+nd
#define right (st+en)/2 +1,en,nd+nd+1
const int MAX=200000;
long long tree[4*MAX];
vector<long long>adj[MAX+5];
long long start[MAX+5];
long long endd[MAX+5];
long long flatArray[MAX+5];
long long flat[MAX+5];
bool visited[MAX+5];
long long timer,ind;
void buildTree(long long st,long long en,long long nd)
{
    if(st==en)
    {
        tree[nd]=flat[st];
        return;
    }
    buildTree(left);
    buildTree(right);
    tree[nd]=tree[nd+nd]+tree[nd+nd+1];


}
long long getSum(long long st,long long en,long long nd,long long L,long long R)
{
    if(L<=st && en<=R)
        return tree[nd];
    if(en<L || R<st)
        return 0;
    return (getSum(left,L,R)+ getSum(right,L,R));
}
void pointUpdate(long long st,long long en,long long nd,long long idx,long long v)
{
    if(en<idx || idx<st)
        return;
    if(st==en)
    {
        tree[nd]=v;
        return;
    }
    pointUpdate(left,idx,v);
    pointUpdate(right,idx,v);
    tree[nd]=tree[nd+nd]+tree[nd+nd+1];
}
void dfs(long long u,long long p)
{
    start[u]=++timer;
    visited[u]=true;
    flatArray[ind++]=u;
    for(auto it:adj[u])
    {
        if(it!=p)
        {
            dfs(it,u);
        }
    }
    endd[u]=timer;
}

int main()
{
    long long n,q;
    cin>>n>>q;
    long long ar[n+1];
    for(long long i=1; i<=n; i++)
        cin>>ar[i];
    for(long long i=1; i<n; i++)
    {
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);

    for(long long i=0; i<n; i++)
        flat[i]=ar[flatArray[i]];
//    for(long long i=0;i<n;i++)
//        cout<<flat[i]<<" ";
//        cout<<endl;
    buildTree(0,n-1,1);
//    for(long long i=1;i<=20;i++)
//        cout<<i<<" "<<tree[i]<<endl;
//    puts("");
//    for(long long i=1;i<=n;i++)
//    {
//        cout<<start[i]<<" "<<endd[i]<<endl;
//    }
    while(q--)
    {
        long long type;
        cin>>type;
        if(type==2)
        {
            long long node;
            cin>>node;
            long long L=start[node];
            long long R=endd[node];
            cout<<getSum(0,n-1,1,L-1,R-1)<<"\n";
        }
        else if(type==1)
        {
            long long idx,v;
            cin>>idx>>v;
            long long im=start[idx];
            pointUpdate(0,n-1,1,im-1,v);

        }
    }
}

