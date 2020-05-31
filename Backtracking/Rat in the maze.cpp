
#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends



/*bool chk(int i, int j,int v[][MAX] ,vector<vector<bool>>vis,int n)
{
    if(i==-1||j==-1||i==n||j==n||vis[i][j]==true||v[i][j]==0)
        return false;
    return true;
}

void __bt(int v[][MAX], int n,int i, int j,string &s, vector<vector<bool>>vis,vector<string> &ans)
{
    if(i==-1||j==-1||i==n||j==n||vis[i][j]==true||v[i][j]==0)
        return;

    if(i==n-1&&j==n-1)
    {
        ans.push_back(s);
        return;
    }
     vis[i][j]=true;
    if(chk(i, j+1, v, vis,n))
    {
        s+="R";
        __bt(v, n, i, j+1,s,vis,ans);
        s.pop_back();
    }
    if(chk(i, j-1, v, vis,n))
    {
        s+="L";
        __bt(v, n, i, j-1,s,vis,ans);
        s.pop_back();
    }
    if(chk(i-1, j, v, vis,n))
    {
        s+="U";
        __bt(v, n, i-1, j,s,vis,ans);
        s.pop_back();
    }
    if(chk(i+1, j, v, vis,n))
    {
        s+="D";
        __bt(v, n, i+1, j,s,vis,ans);
        s.pop_back();
    }
v[i][j]=false;
}*/
bool isSafe(int row, int col, int m[][MAX],
                 int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||
                  col == n || visited[row][col]
                           || m[row][col] == 0)
        return false;

    return true;
}

// Function to print all the possible
// paths from (0, 0) to (n-1, n-1).
void printPathUtil(int row, int col, int m[][MAX],
              int n, string& path, vector<string>&
               possiblePaths, bool visited[][MAX])
{
    // This will check the initial point
    // (i.e. (0, 0)) to start the paths.
    if (row == -1 || row == n || col == -1
               || col == n || visited[row][col]
                           || m[row][col] == 0)
        return;

    // If reach the last cell (n-1, n-1)
    // then store the path and return
    if (row == n - 1 && col == n - 1) {
        possiblePaths.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[row][col] = true;

    // Try for all the 4 directions (down, left,
    // right, up) in the given order to get the
    // paths in lexicographical order

    // Check if downward move is valid
    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n,
                 path, possiblePaths, visited);
        path.pop_back();
    }

    // Check if the left move is valid
    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n,
                   path, possiblePaths, visited);
        path.pop_back();
    }

    // Check if the right move is valid
    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n,
                   path, possiblePaths, visited);
        path.pop_back();
    }

     // Check if the upper move is valid
    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n,
               path, possiblePaths, visited);
        path.pop_back();
    }

    // Mark the cell as unvisited for
    // other possible paths
    visited[row][col] = false;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> possiblePaths;
    string path;
    bool visited[n][MAX];
    memset(visited, false, sizeof(visited));
    printPathUtil(0, 0, m, n, path,
                      possiblePaths, visited);
    return possiblePaths ;
}

