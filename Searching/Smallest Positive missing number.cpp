#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find missing integer in array
// arr: input array
// n: size of array
int findMissing(int a[], int n) {
    set<int> mp;
    for(int i=0;i<n;i++)
    {
        mp.insert(a[i]);
    }
    for(int i=1;i<1000001;i++)
    {
        if(mp.find(i)==mp.end())
        return i;
    }

}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];

        for(int i=0; i<n; i++)cin>>arr[i];

        cout<<findMissing(arr, n)<<endl;
    }
    return 0;
}   // } Driver Code Ends
