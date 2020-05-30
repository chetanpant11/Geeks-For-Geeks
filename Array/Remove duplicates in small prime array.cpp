#include<bits/stdc++.h>
using namespace std;
vector<int> removeDuplicate(vector<int>& arr, int n);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        vector<int>result = removeDuplicate(A,N);
        for(int i =0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;

    }
}
// } Driver Code Ends
vector<int> removeDuplicate(vector<int>& arr, int n)
{
    vector<int> a(1000,-1);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(a[arr[i]]==-1)
            {a[arr[i]]=arr[i];
            ans.push_back(arr[i]);}
    }
    return ans;
}


