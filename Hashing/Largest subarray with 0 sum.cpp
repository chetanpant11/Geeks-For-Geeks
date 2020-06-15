#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
int maxLen(int a[], int n) {
    unordered_map<int, int>mp;
    mp.insert({0, -1});
    for(int i=1;i<n;i++)
    {
        a[i]=a[i]+a[i-1];
    }

    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(mp.find(a[i])!=mp.end())
        {
            ans=max(ans, i-mp[a[i]]);
        }
        else
        mp[a[i]]=i;
    }
    if(ans==INT_MIN)
    return 0;
    return ans;
}




