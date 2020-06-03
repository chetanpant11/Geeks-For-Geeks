
#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);

        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }

        vec = productExceptSelf(arr,n);   // function call

        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
    vector<long long int>left(n);
    vector<long long int>right(n);
    vector<long long int>ans(n);
    if(n==1)
    {
        ans[0]=1;
        return ans;
    }
    left[0]=a[0];
    for(int i=1;i<n;i++)
    {
        left[i]=a[i]*left[i-1];
    }
    right[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=a[i]*right[i+1];
    }
    ans[0]=right[1];
    ans[n-1]=left[n-2];
    for(int i=1;i<n-1;i++)
    {
        ans[i]=left[i-1]*right[i+1];
    }
    return ans;
}
