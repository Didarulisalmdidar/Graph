#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
int X[]= {-1,1,0,0};
int Y[]= {0,0,-1,1};
char seq[MAX][MAX];
int dist[MAX][MAX];
string res;
void bfs(string s[],int a,int b,int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            dist[i][j]=MAX/2;
    }
    dist[a][b]=0;
    seq[a][b]='0';
    queue<int>q;
    q.push(a);
    q.push(b);
    s[a][b]='*';
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        int b=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int x=a+X[i];
            int y=b+Y[i];
            if(x>=0 && y>=0 && x<n && y<m && (s[x][y]=='.' || s[x][y]=='B'))
            {
                if(i==0)
                    seq[x][y]='U';
                if(i==1)
                    seq[x][y]='D';
                if(i==2)
                    seq[x][y]='L';
                if(i==3)
                    seq[x][y]='R';
                // cout<<x<<" "<<y<<" "<<seq[x][y]<<endl;
                dist[x][y]=dist[a][b]+1;
                q.push(x);
                q.push(y);
                s[x][y]='*';
            }
        }
    }
}
void backtrac(int d,int e)
{
    while(seq[d][e]!='0')
    {
        res+=seq[d][e];
        if(seq[d][e]=='L')
            e++;
        else if(seq[d][e]=='R')
            e--;
        else if(seq[d][e]=='U')
            d++;
        else if(seq[d][e]=='D')
            d--;
        //cout<<d<<" "<<e<<" "<<seq[d][e]<<endl;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;


}
int main()
{
    int n,m;
    cin>>n>>m;
    string s[n+1];
    for(int i=0; i<n; i++)
        cin>>s[i];
    int a,b,d,e;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(s[i][j]=='A')
            {
                a=i;
                b=j;
            }
            if(s[i][j]=='B')
            {
                d=i;
                e=j;
            }
        }
    }
    bfs(s,a,b,n,m);
    if(dist[d][e]==MAX/2)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        int ans=dist[d][e];
        cout<<ans<<endl;
        backtrac(d,e);
    }

}

