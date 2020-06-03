#include <bits/stdc++.h>

using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q);

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        auto v = processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}// } Driver Code Ends

void pre_compute(int a[],  vector<int>&left, vector<int>&right)
{
    left[0]=0;
    int k=0;
    for(int i=1;i<left.size();i++)
    {
        if(a[i]>a[i-1])
        {
            k=i;
            left[i]=k;
        }
        else
        left[i]=k;
    }
    right[right.size()-1]=right.size()-1;
    int kk=right.size()-1;
    for(int i=left.size()-2;i>=0;i--)
    {
        if(a[i]>a[i+1])
        {
            kk=i;
            right[i]=kk;
        }
        else
        right[i]=kk;
    }
}

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q)
{
    vector<int>left(n);
    vector<int>right(n);
    pre_compute(a, left, right);
    vector<bool> ans;
    for(int i=0;i<queries.size();i++)
    {
        int l=queries[i].first;
        int r=queries[i].second;

        right[l]>=left[r]?ans.push_back(true):ans.push_back(false);
    }
    return ans;
}
