#include <bits/stdc++.h>
#define ll long long int
using namespace std;

unsigned long long int mod =1e9+7;

bool can_place(vector<vector<int>>&v,int i,int row, int col)
{
    //cout<<1;
    for(int k=0;k<9;k++)
    {
        if(v[k][col]==i)
            return false;
        if(v[row][k]==i)
            return false;
    }
    int col_box=int(col/3);
    int row_box=int(row/3);

    for(int k=row_box*3;k<((row_box*3)+3);k++)
    {
        for(int j=col_box*3;j<((col_box*3)+3);j++)
        {
            if(v[k][j]==i)
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>&v,int row, int col)
{
    if(col==v.size())
        return solve(v, row+1, 0);

    if(row==v.size())
    {
        return true;
    }
    if(v[row][col]!=0)
    {
        return solve(v,row,col+1);
    }
    for(int i=1;i<=9;i++)
    {
        if(can_place(v,i,row,col))
        {
            v[row][col]=i;
            bool suc=solve(v,row,col+1);
            if(suc==true)
             return  true;
          v[row][col]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

        cin>>v[i][j];
        }
    }
    solve(v,0,0);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

