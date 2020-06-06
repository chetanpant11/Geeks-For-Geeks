#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int circularSubarraySum(int a[], int n){
    int max1=0;
    int max2=0;
    for(int i=0;i<n;i++)
    {
        max1+=a[i];
        if(max1<0)
        {
            max1=0;
        }
        if(max1>max2)
        {
            max2=max1;
        }
    }
    int sum=0;
    int huge=INT_MIN;
    for(int i=0;i<n;i++)
    {
        huge=max(huge, a[i]);
        sum+=a[i];
        a[i]=-a[i];
    }
    //cout<<sum;
    int max=0;
    int max_so_far=0;
    for(int i=0;i<n;i++)
    {
        max+=a[i];
        if(max<0)
        {
            max=0;
        }
        if(max>max_so_far)
        {
            max_so_far=max;
        }
    }
    //sum=sum-(-max_so_far);
    if(sum-(-max_so_far)>max2)
        return(sum-(-max_so_far));
    else if(max2!=0)
        return max2;
    else
    return huge;


}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;

	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];


	    cout << circularSubarraySum(arr, num) << endl;

	}

	return 0;
}  // } Driver Code Ends
