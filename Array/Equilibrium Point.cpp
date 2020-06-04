#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

#include<bits/stdc++.h>
// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n) {
    if(n==1)
    return 1;

    vector<int> l(n);
    l[0]=a[0];
    for(int i=1;i<n;i++)
    {
        l[i]=a[i]+l[i-1];
    }

    vector<int> r(n);
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        r[i]=a[i]+r[i+1];
    }
    for(int i=1;i<n-1;i++)
    {
        if(l[i-1]==r[i+1])
        return i+1;
    }
    return -1;
}
