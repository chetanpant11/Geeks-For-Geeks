#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to find level of node X

g[] : adjacency list of the given graph
N : number of vertices
X : The destination node
*/
int levels(vector<int> g[], int n, int X)
{
    vector<bool>vis(n,false);
    queue<int> q;
    q.push(0);
    vis[0]=true;
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            int k=q.front();
            q.pop();
                vis[k]=true;
            if(k==X)
                return level;
            else
            for(auto s:g[k])
            {
                if(vis[s]==false)
                {
                vis[s]=true;
                q.push(s);
                }
            }
        }
        level++;

    }
    return -1;
}

// { Driver Code Starts.

int main() {

    int t;
    cin>>t;

    while (t--) {

        int n, e;
        cin >> n >> e;
        vector<int> g[n];
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int x;
        cin >> x;

        cout << levels(g, n, x) << endl;
    }

    return 0;
}  // } Driver Code Ends
