#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int n)
{
    int count =1;
    int curr_element=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]==curr_element)
        count++;

        else if(count==0)
        {
            curr_element=a[i];
            count++;
        }
        else
        count--;
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==curr_element)
        count++;
    }
    if(count>n/2)
    return curr_element;
    else return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];

        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }

        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
