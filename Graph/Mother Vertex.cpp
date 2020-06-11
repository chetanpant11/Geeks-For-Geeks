//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*

 * Function to find if there is a mother vertex in the given graph
 * V: number of vertices in the graph
 * g[]: graph representation
 */
bool dfs(vector<int> g[], vector<bool>&vis, int i)
{
    vis[i]=true;

    for(auto s: g[i])
    {
        if(vis[s]==false)
        {
        dfs(g, vis, s);
        }
    }
   // return false;
}

int findMother(int n, vector<int> g[])
{
   vector<bool> vis(n,false);
   int c=0;
   for(int i=0;i<n;i++)
   {
      // int c=1;
       if(vis[i]==false)
       {
            dfs(g, vis,i);
            c=i;
       }
   }
   fill(vis.begin(), vis.end(),false);
   dfs(g, vis, c);
   for(int i=0;i<n;i++)
   {
       if(vis[i]==false)
       return -1;
   }
   return c;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;

        vector<int> adj[num];

        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }

        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}   // } Driver Code Ends
