#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int a[], int n){
    int max_sum=0;
    int max_so_far=INT_MIN;
    int max_element=INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_element=max(max_element, a[i]);
        max_sum+=a[i];

        if(max_sum<0)
        max_sum=0;

        else if(max_sum>max_so_far)
        max_so_far=max_sum;
    }
    if(max_so_far==INT_MIN)
    return max_element;
    else
    return max_so_far;

}

// { Driver Code Starts.

int main()
{
    int t,n;

    cin>>t; //input testcases
    while(t--) //while testcases exist
    {

        cin>>n; //input size of array

        int a[n];

        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array

        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
