
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends


// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll a[], ll n)
{
    vector<ll>dp(n);
    if(n==0)
    return 0;
    if(n==1)
    return a[0];
    if(n==2)
    return max(a[0],a[1]);

    dp[0]=a[0];
    dp[1]=max(a[0], a[1]);
    for(int i=2; i<n;i++)
    {
        dp[i]=max(a[i]+dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
