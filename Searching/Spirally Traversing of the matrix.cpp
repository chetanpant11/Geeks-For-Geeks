#include <iostream>
using namespace std;

#define SIZE 105

void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]);

int main() {
	int T = 0;

	scanf("%d",&T);

	while(T--)
	{
        int m,n;
        scanf("%d",&m);
        scanf("%d",&n);
	    int ar[SIZE][SIZE] = {{0}};
	    int i = 0;
	    int j = 0;
	    int row = 0;
	    int col = 0;

	    for(i=0; i<m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            scanf("%d",&ar[i][j]);
	        }
	    }

	    spirallyTraverse(m, n, ar);
	    cout<<endl;

	}
	return 0;
}// } Driver Code Ends


//Complete this function
void spirallyTraverse(int n, int m, int v[SIZE][SIZE]){

    int row_start=0,row_end=n-1, col_start=0, col_end=m-1;
    while(row_start<=row_end&&col_start<=col_end)
    {
        for(int i=col_start;i<=col_end;i++)
            {
                cout<<v[row_start][i]<<" ";
            }
            row_start++;
        for(int i=row_start;i<=row_end;i++)
            {
                cout<<v[i][col_end]<<" ";
            }
            col_end--;
        if(row_start<=row_end){
        for(int i=col_end;i>=col_start;i--)
            {
                cout<<v[row_end][i]<<" ";
            }
            row_end--;}
        if(col_start<=col_end)
            {
        for(int i=row_end;i>=row_start;i--)
            {
                cout<<v[i][col_start]<<" ";
            }
            col_start++;
            }
    }
}

