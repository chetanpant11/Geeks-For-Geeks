#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);


 // } Driver Code Ends


// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x)
{
    long long int i=0,j=x;
    long long int mid;
    while(i<=j)
    {
        mid=i+(j-i)/2;
        if((mid*mid)==x)
        return mid;

        else if(mid*mid<x && (mid+1)*(mid+1)>x)
        return mid;

        else if(mid*mid<x)
        i=mid+1;

        else
        j=mid-1;
    }
    return mid;
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;
}
  // } Driver Code Ends
