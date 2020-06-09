// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int countOccurence(int arr[], int n, int k);
// Position this line where user code will be pasted.

/* Driver program to test above function */
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        cout << countOccurence(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to find element with count more than n/k times
// arr: input array
int countOccurence(int a[], int n, int k) {
    unordered_map<int, int>mp;
    set<int>s;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
        s.insert(a[i]);
    }
    int count=0;
    for(auto l:s)
    {
        if(mp[l]>n/k)
        count++;
    }
    return count;
}
