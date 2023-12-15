#include<bits/stdc++.h>
using namespace std;
//#define left st, (st+en)/2, nd+nd
//#define right (st+en)/2 +1,en,nd+nd+1
const int MAX=200000;
vector<long long>adj[MAX+5];
long long start[MAX+5];
long long endd[MAX+5];
long long flatArray[MAX+5];
long long flat[MAX+5];
bool visited[MAX+5];
long long timer,ind;
set<int>* segment;
void build(int i, int s, int e, int arr[])
{
    if (s == e)
    {
        segment[i].insert(arr[s]);
        return;
    }

    build(2 * i, s, (s + e) / 2, arr);
    build(1 + 2 * i, 1 + (s + e) / 2, e, arr);

    segment[i].insert(segment[2 * i].begin(),
                      segment[2 * i].end());

    segment[i].insert(segment[2 * i + 1].begin(),
                      segment[2 * i + 1].end());
}


set<int> query(int node, int l, int r, int a, int b)
{
    set<int> left, right, result;

    if (b < l || a > r)
        return result;

    if (a <= l && r <= b)
        return segment[node];

    left = query(2 * node, l, (l + r) / 2, a, b);
    result.insert(left.begin(), left.end());

    right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b);
    result.insert(right.begin(), right.end());
    return result;
}
void init(int n)
{
    int h = (int)ceil(log2(n));
    h = (2 * (pow(2, h))) - 1;
    segment = new set<int>[h];
}

void getDistinct(int l, int r, int n)
{
    set<int> ans = query(1, 0, n - 1, l, r);

    cout << ans.size() <<" ";
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
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=1; i<=n; i++)
        cin>>ar[i];
    for(long long i=1; i<n; i++)
    {
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    int arr[n+1];
    for(long long i=0; i<n; i++)
        arr[i]=ar[flatArray[i]];

    init(n);

    build(1, 0, n - 1, arr);
    for(int i=1; i<=n; i++)
    {
        int L=start[i];
        int R =endd[i];
        getDistinct(L-1,R-1,n);
    }

    return 0;
}

