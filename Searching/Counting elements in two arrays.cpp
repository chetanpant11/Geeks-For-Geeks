
// C++ implementation of For each element in 1st
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>

using namespace std;

// function returns the index of largest element
// smaller than equal to 'x' in 'arr'. For duplicates
// it returns the last index of occurrence of required
// element. If no such element exits then it returns -1.
int binary_search(int arr[], int l, int h, int x);

// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
vector <int> countEleLessThanOrEqual(int arr1[], int arr2[],
                             int m, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        vector <int> res = countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";

        cout<<endl;
    }
    return 0;
}// } Driver Code Ends


// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
vector<int> countEleLessThanOrEqual(int v[], int v2[],
                             int n, int m)
{
    sort(v2, v2+m);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        bool chk=false;
        int a=v[i];
        //cout<<a<<" ";
        int l=0, h=m-1;
        while(l<=h)
        {
           int mid=l+(h-l)/2;
           if(v2[mid]<=a&&v2[mid+1]>a)
               {
                   ans.push_back(mid+1);
                   chk=true;
                   break;
                }
           else if(mid==0&&v2[mid]>a)
           {
                   ans.push_back(0);
                   chk=true;
                   break;
            }
           else if(v2[mid]>a)
            h=mid-1;
           else
            l=mid+1;
        }
        if(chk==false)
        {
            ans.push_back(m);
        }
    }
return ans;
}
