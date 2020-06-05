//Initial template for C++

#include<iostream>
using namespace std;
int maxArea(int A[], int len);

 // } Driver Code Ends


//User function template for C++

long long maxArea(long long a[], int len)
{
    long long ans=0;
    long long i=0, j=len-1;
    while(i<=j)
    {
        long long mini=min(a[i],a[j]);
        ans=max(ans, mini*(j-i));
        if(a[i]<a[j])
        i++;
        else
        j--;
    }
    return ans;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
