#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


// Function to find the transition point
int transitionPoint(int a[], int n) {
    if(a[0]==1)
    return 0;

    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1])
        return i+1;
    }
    return -1;
}
