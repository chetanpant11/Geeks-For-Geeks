//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

bool chk(int i, int j, int n, int m)
{
    if(i<0||j<0||i>=n||j>=m)
    return false;

    return true;

}

int rotOranges(vector<vector<int>>&v, int n, int m)
{
   int count=-1;
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==2)
            {
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        count++;
        int ss=q.size();

        for(int k=0;k<ss;k++)
        {
            pair<int, int>temp=q.front();
            q.pop();
            int i=temp.first, j=temp.second;
            if(chk(i+1,  j, n, m)&&v[i+1][j]==1)
            {
                v[i+1][j]=2;
                q.push({i+1,j});
            }
            if(chk(i-1,  j,n,m)&&v[i-1][j]==1)
            {
                v[i-1][j]=2;
                q.push({i-1,j});
            }
            if(chk(i,  j+1,n,m)&&v[i][j+1]==1)
            {
                v[i][j+1]=2;
                q.push({i,j+1});
            }
            if(chk(i,  j-1,n,m)&&v[i][j-1]==1)
            {
                v[i][j-1]=2;
                q.push({i,j-1});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==1)
            {
                return -1;
            }
        }
    }
    return count;

}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
}  // } Driver Code Ends
