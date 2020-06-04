#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int maxIndexDiff(int a[], int n)
{
   vector<int>v(n);
    v[0]=a[0];
    for(int i=1;i<n;i++)
    {
        v[i]=min(a[i],v[i-1]);
    }
    vector<int>l(n);
    l[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        l[i]=max(a[i],l[i+1]);
    }
    //int ans=INT_MIN;
    int i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n)
    {
        if (v[i] <= l[j])
        {
            maxDiff = max(maxDiff, j - i);
            j = j + 1;
        }
        else
            i = i + 1;
    }

    return maxDiff;
}

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];
        for (int i = 0; i<num; i++)
            cin>>arr[i];

        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        cout<<maxIndexDiff(arr, num)<<endl;

    }
    return 0;
}   // } Driver Code Ends
