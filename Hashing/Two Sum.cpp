// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool keypair(vector<int> array, int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        for (int i = 0; i < n; i++) cin >> array[i];
        cout << (keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// A[] : the input array of positive integers
// N : size of the array arr[]
// X : the required sum
bool keypair(vector<int> a, int n, int x) {
    unordered_map<int,int>  s;
    for(int i=0;i<n;i++)
    {
        s[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(x-a[i])!=s.end())
        {
            if(x-a[i]==a[i]&&s[x-a[i]]>1)
            {
             return true;
            }
            else if(x-a[i]!=a[i])
            return true;
        }
    }
    return false;

}
