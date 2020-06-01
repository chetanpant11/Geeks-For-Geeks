#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

void __bt(vector<int> v, int index,vector<int>&a,vector<vector<int>>&ans)
{

    ans.push_back(a);

    for(int i=index;i<v.size();i++)
    {
        if(i>index && v[i]==v[i-1])
            continue;
        a.push_back(v[i]);
        __bt(v, i+1, a,ans);
        a.pop_back();
    }

}
void func (vector <int> v)
{
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    vector<int> a;
    __bt(v, 0,a,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<"(";
        for(int j=0;j<ans[i].size();j++)
            {
                cout<<ans[i][j];
                if(j!=ans[i].size()-1)
                cout<<" ";
            }
        cout<<")";
    }
   cout<<endl;
}

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        func(A);

    }
}	  // } Driver Code Ends
