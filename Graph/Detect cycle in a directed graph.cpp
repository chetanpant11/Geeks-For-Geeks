

 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool dfs(vector<int> g[], vector<bool>&vis, int i,vector<bool>&stack)
{
    if(vis[i]==false)
    {
        vis[i]=true;
        stack[i]=true;
    }
    for(auto k: g[i])
    {
        if(vis[k]==false&& dfs(g, vis, k, stack))
        {
            return true;
        }
        else if(stack[k])
        return true;
    }
stack[i]=false;
return false;
}


bool isCyclic(int n, vector<int> g[])
{
    bool chk=false;
    vector<bool> stack(n, false);
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            stack[i]=true;
            if(dfs(g,vis, i, stack))
            {chk=true;
            break;}
        }
    }
    return chk;
}

// { Driver Code Starts.

int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}  // } Driver Code Ends
