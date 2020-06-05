#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends




// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int a[], int n){
    vector<int> left(n);
    vector<int> right(n);
    left[0]=a[0];
    for(int i=1;i<n;i++)
    {
        left[i]=max(left[i-1], a[i]);
    }
    right[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],a[i]);
    }
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        ans+=min(left[i], right[i])-a[i];
    }
    return ans;
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;

        cin >> n;

        int a[n];

        for(int i =0;i<n;i++){
            cin >> a[i];
        }

        cout << trappingWater(a, n) << endl;

    }

    return 0;
}  // } Driver Code Ends
