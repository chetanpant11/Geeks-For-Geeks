#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        	cin >> a[i];
        vector <int> result = countDistinct(a, n, k);
        for (int i : result)
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


vector <int> countDistinct (int a[], int n, int k) {
    unordered_map<int, int>mp;
    for(int i=0;i<k;i++)
    {
        mp[a[i]]++;
    }
    vector<int> ans;
    int i=0,  j=k-1;
    while(j!=n)
    {
        ans.push_back(mp.size());
        j++;
        mp[a[j]]++;
        i++;
        mp[a[i-1]]--;
        if(mp[a[i-1]]==0)
            mp.erase(a[i-1]);
    }

    return ans;
}
