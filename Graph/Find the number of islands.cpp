#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
void dfs(int i,int j,vector<vector<bool>> &dp,vector<vector<int>> &A)
{
    if(i<0||j<0||i>=A.size()||j>=A[0].size())
    return;

   if(A[i][j]==1&&dp[i][j]==false)
   {
     dp[i][j]=true;
      dfs(i-1,j,dp,A);
      dfs(i,j-1,dp,A);
      dfs(i+1,j,dp,A);
      dfs(i,j+1,dp,A);
      dfs(i-1,j-1,dp,A);
      dfs(i+1,j+1,dp,A);
      dfs(i-1,j+1,dp,A);
      dfs(i+1,j-1,dp,A);
   }
return ;
}
int solve(vector<vector<int>>&A)
{
    vector<vector<bool>> dp(A.size(),vector<bool>(A[0].size(),false));
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
        if(A[i][j]==1&&dp[i][j]==false)
        {
          dfs(i,j,dp,A);
          count++;
        }
        }
}
return count;
}

int findIslands(vector<int> A[], int n, int m) {
    vector<vector<int>>k(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            k[i][j]=A[i][j];
        }
    }
    return solve(k);
}
