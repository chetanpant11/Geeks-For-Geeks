#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
    int curr_sum=0;
    int curr_val=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=a[i];
        curr_val+=a[i]*i;
    }
    int ans=curr_val;
    for(int i=1;i<n;i++)
    {
        int next_val=curr_val-(curr_sum-a[i-1])+a[i-1]*(n-1);
        curr_val=next_val;
        ans=max(next_val,ans);
    }
    return ans;
}
