#include<bits/stdc++.h>
using namespace std;
// Driver Code Ends
// This function rotate array by D elements
// arr: input elements
// n: size of the array
void rotateArr(int arr[], int d, int n){
    int k=__gcd(d,n);
    int j,temp;
    for(int i=0;i<k;i++)
    {
        j=i;
        temp=arr[i];
        while(1)
        {
            int a=(j+d)%n;
            if(a==i)
               break;

            else
            arr[j]=arr[a];
            j=a;
        }
        arr[j]=temp;
    }
}
// { Driver Code Starts.

int main() {
	//code

	int t;
	cin >> t;

	while(t--){
	    int n, d;
	    cin >> n >> d;

	    int arr[n];

	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }

	    rotateArr(arr, d,n);

	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;

	}

	return 0;
}  // } Driver Code Ends
