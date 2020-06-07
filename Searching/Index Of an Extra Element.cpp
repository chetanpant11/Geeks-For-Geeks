#include <bits/stdc++.h>
using namespace std;
int findExtra(int a[], int b[], int n);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        cout << findExtra(a, b, n) << endl;
    }
}// } Driver Code Ends


/*Complete the function below*/
int findExtra(int a[], int b[], int n) {
    int i=0,j=n-1;
    int index=n;
    while(i<=j)
    {
        int mid=i+(j-i)/2;
        if(a[mid]==b[mid])
        i=mid+1;
        else
        {
            index = mid;
            j = mid - 1;
        }
    }
    return index;
}
