#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
vector<int> duplicates(int a[], int n)

{
   vector<int>v(n,-1);
   vector<int>ans;
   for(int i=0;i<n;i++)
   {
      v[a[i]]++;
      //cout<<v[a[i]];
   }
   for(int i=0;i<n;i++)
   {
       //cout<<v[i];
       if(v[i]>=1)
        {
            //cout<<i<<" ";
            ans.push_back(i);
        }
   }
   if(ans.size()==0)
    ans.push_back(-1);
   return ans;
}

