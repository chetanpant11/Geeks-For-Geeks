// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

int MissingNumber(vector<int>& a, int n) {
    int sum=0;
    for(int i=0;i<a.size();i++)
    {
        sum+=a[i];
    }
    //cout<<sum;
    int sum2=(n*(n+1))/2;
    return (sum2-sum);
    //return 0;

}
