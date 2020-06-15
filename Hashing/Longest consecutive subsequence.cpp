#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }

    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int a[], int n)
{
  unordered_map<int , int> mp;
  for(int i=0;i<n;i++)
  {
      mp[a[i]]++;
  }
  int ans=INT_MIN;
  for(int i=0;i<n;i++)
  {
      int count=0;
      if(mp.find(a[i]-1)!=mp.end())
      continue;

      else
      {
          int k=a[i];
          while(true)
          {
              count++;
              k++;
              if(mp.find(k)!=mp.end())
              continue;
              else break;

          }
      }
      ans=max(ans, count);
  }
  return ans;
}
