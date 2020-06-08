#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> v, long long n, long long x){
    long long int i=0;
    long long int j=n-1;
    if(v[j]<x)
    return j;
    while(i<=j)
    {
        long long int mid=i+(j-i)/2;
        if (v[mid] == x)
        return mid;

        if (mid > 0 && v[mid - 1] <= x
        && x < v[mid])
        return mid - 1;

        else if(v[mid]>x)
        j=mid-1;

        else
        i=mid+1;
    }
    return -1;

    // Your code here

}

// { Driver Code Starts.

int main() {

	long long t;
	cin >> t;

	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;

	    vector<long long> v;

	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }

	    cout << findFloor(v, n, x) << endl;

	}

	return 0;
}  // } Driver Code Ends
