#include <stdio.h>
#include <iostream>
#include <stdlib.h> // for abs()
#include <limits.h> // for INT_MAX
using namespace std;
long long minDist(long long arr[], long long n, long long x, long long y);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long a[n];
        for (long long i = 0; i < n; i++) cin >> a[i];
        long long x, y;
        cin >> x >> y;
        cout << minDist(a, n, x, y) << endl;
    }
    return 0;
}// } Driver Code Ends

/*Complete the function below*/
long long minDist(long long a[], long long n, long long x, long long y) {
   long long i, prev, mini=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(a[i]==x||a[i]==y)
        {
            prev=i;
            break;
        }
    }
    for(;i<n;i++)
    {
        if(a[i]==x||a[i]==y)
        {
            if(a[i]!=a[prev]&&abs(i-prev)<mini)
            {
                mini=abs(i-prev);
                prev=i;
            }
            else
            prev=i;
        }
    }
    if(mini==INT_MAX)
    return -1;
    return mini;

}
