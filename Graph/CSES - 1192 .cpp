/// Counting Rooms
#include<bits/stdc++.h>
using namespace std;
const int MAX=100000;
int X[]={-1,1,0,0};
int Y[]={0,0,-1,1};
void dfs(string ar[],int n,int m,int a,int b)
{
    ar[a][b]='*';
    for(int i=0;i<4;i++)
    {
        int x=a+X[i];
        int y=b+Y[i];
        if(x>=0 && y>=0 && x<n && y<m && ar[x][y]== '.')
            dfs(ar,n,m,x,y);
    }

}
int main()
{
    int n,m;
    cin>>n>>m;
    string ar[n+1];
    for(int i=0;i<n;i++)
        cin>>ar[i];
        int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ar[i][j]== '.')
            {
                dfs(ar,n,m,i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

