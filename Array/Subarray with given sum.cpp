#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int a[], int n, int s){
    int i=0,j=1;
    int sum=a[0];
    bool chk=false;
        while(j<=n)
        {

             if(sum==s)
                 {
                 cout<<i+1<<" "<<j;
                 chk=true;
                 break;
                 }
             else if(sum<s)
                 {
                 sum+=a[j];
                 j++;
                 }
             else
                 {
                 sum-=a[i];
                 i++;
                }
        }
        if(chk==false)
        cout<<-1;
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        subarraySum(arr, n, s);
        cout<<endl;

    }
	return 0;
}  // } Driver Code Ends
