#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main() {
    // your code goes here
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int a[], int n) {
    unordered_map<int , int >mp;
    mp[0]=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            a[i]=-1;
    }
    for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]+a[i];
    }
    int maxl=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(mp.find(a[i])!=mp.end())
        {
            if(maxl<(i-mp[a[i]]))
            maxl=i-mp[a[i]];
        }
        else
        mp[a[i]]=i;
    }
    if(maxl!=INT_MIN)
    return maxl;
    else return 0;
}
