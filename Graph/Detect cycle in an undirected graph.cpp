#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(vector<int> g[], vector<int>&vis, int i, int parent)
{
    if(vis[i]==false)
    vis[i]=true;

    for(auto s: g[i])
    {
        if(vis[s]==true&& s!=parent)
        {
            return true;
        }
        else if(vis[s]==false)
        {
            vis[s]=true;
            if(dfs(g, vis, s, i))
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int n)
{
    bool chk=false;
    vector<int> vis(n, false);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            if(dfs(g, vis, i, -1))
            {
                return  true;
            }
        }
    }
    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
