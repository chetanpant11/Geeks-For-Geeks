
#define MAX 1000
using namespace std;

bool is_possible(vector<vector<int>> &a, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(MAX, vector<int>(MAX, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> a[i][j];

        cout << is_possible(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++


// M : input matrix
class number{
    public:
    int row;
    int col;
    number(int r,int c){
       row=r;
       col=c;
    }
};

int func(vector<vector<int>> grid,int size){
    number source(0,0);
    number desti(0,0);
    bool vis[size][size]={false};
     for(int i=0;i<size;i++){
	        for(int j=0;j<size;j++){
	           if(grid[i][j]==1){
	               source.row=i;
	               source.col=j;
	           }
	            if(grid[i][j]==2){
	               desti.row=i;
	               desti.col=j;
	           }
	            if(grid[i][j]==0){
	               vis[i][j]=true;
	           }

	        }
	    }
	    queue<number> q;

	    q.push(source);
	    vis[source.row][source.col]=true;
	    while(!q.empty()){
	        number n=q.front();
	        q.pop();
	        if(n.row==desti.row && n.col==desti.col){
	            return 1;
	        }
	        if(n.row+1 < size && !vis[n.row+1][n.col]){
	            number k(n.row+1,n.col);
	            q.push(k);
	            vis[n.row+1][n.col]=true;
	        }
	         if(n.row-1 >=0 && !vis[n.row-1][n.col]){
	            number k(n.row-1,n.col);
	            q.push(k);
	            vis[n.row-1][n.col]=true;
	        }
	         if(n.col+1 < size && !vis[n.row][n.col+1]){
	            number k(n.row,n.col+1);
	            q.push(k);
	            vis[n.row][n.col+1]=true;
	        }
	         if(n.col-1 >=0 && !vis[n.row][n.col-1]){
                number k(n.row,n.col-1);
	            q.push(k);
	            vis[n.row][n.col-1]=true;
	        }
	    }
	    return 0;
}


bool is_possible(vector<vector<int>>&mat, int n) {
    return func(mat,n);
}

