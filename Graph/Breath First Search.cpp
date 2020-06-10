#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int n) {
    vector<bool> vis(n, false);
    queue<int> q;
    vector<int> ans;
    q.push(0);
    vis[0]=true;
    //ans.push_back(0);
    while(!q.empty())
    {
        int temp=q.front();
        //if(vis[temp]==false)
        ans.push_back(temp);
        q.pop();
        for(auto s: g[temp])
        {
            if(vis[s]==false)
            {
                vis[s]=true;
                q.push(s);
            }
        }
    }
    return ans;

}
