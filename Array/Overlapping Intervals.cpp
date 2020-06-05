//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }

        res = overlappedInterval(arr,n);


        for(int i=0;i<res.size();i++)
            cout << res[i].first << " " << res[i].second << " " ;

        cout<<endl;
    }
}
// } Driver Code Ends


//User function template for C++

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> v, int n) {
    sort(v.begin(), v.end());
    for(int i=1;i<n;i++)
    {
        if(v[i].first<=v[i-1].second)
        {
           int first=min(v[i].first, v[i-1].first);
           int second=max(v[i].second, v[i-1].second);
           v[i].first=first;
           v[i].second=second;
           v[i-1].first=-1;
           v[i-1].second=-1;
        }
    }
    sort(v.begin(), v.end());
    while(v[0].first==-1)
    {
        v.erase(v.begin());
    }
    return v;
}
