//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends


//User function Template for C++
double __binarysearch(const vector<int> &A,const vector<int>&B)
{
    if(A.size()>B.size())
    {
      return (__binarysearch(B,A));
    }
   int smallsizevector=A.size();
   int largesizevector=B.size();
   int total=smallsizevector+largesizevector;
   int low=0;
   int high=smallsizevector;
   while(low<=high)
   {
    int midsmall=low+(high-low)/2;
    int midlarge=(total+1)/2-midsmall;

    int leftpartsmall=(midsmall==0)?INT_MIN:A[midsmall-1];

    int rightpartsmall=(midsmall==smallsizevector)?INT_MAX:A[midsmall];

    int leftpartlarge=(midlarge==0)?INT_MIN:B[midlarge-1];

    int rightpartlarge=(midlarge==largesizevector)?INT_MAX:B[midlarge];

   if(leftpartsmall<=rightpartlarge &&rightpartsmall>=leftpartlarge)
   {
     if(total%2==0)
     {
       return (double)(((double)max(leftpartlarge,leftpartsmall)+(double)min(rightpartlarge,rightpartsmall))/2);
     }
      else
      {
         return (double)max(leftpartsmall,leftpartlarge);
      }
    }
    else if(rightpartsmall>leftpartlarge)
    {
        high=midsmall-1;
    }
    else{
        low=midsmall+1;
        }
    }
}

double MedianOfArrays(vector<int>& A, vector<int>& B)
{
    return __binarysearch(A,B);

}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin>>array1[i];
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin>>array2[i];
        cout<<MedianOfArrays(array1, array2)<<endl;
    }
    return 0;
}


  // } Driver Code Ends
