#include<bits/stdc++.h>
using namespace std;
int max_path_sum(int [], int [], int , int );

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        int result = max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}
// } Driver Code Ends
/*You are required to complete this method*/
 int max_path_sum(int a[], int b[], int l1, int l2)
{
    int i=0,j=0;
    int sum=0,sum1=0,res=0;
    while(i<l1&&j<l2)
    {
        if(a[i]<b[j])
        {
            sum+=a[i++];
        }
        else if(a[i]>b[j])
        {
            sum1+=b[j++];
        }
        else
        {
            res+=max(sum1,sum);
            sum1=0;
            sum=0;
            while(i<l1&&j<l2&&a[i]==b[j])
            {
                res+=a[i++];
                j++;
            }
        }
    }
    while(i<l1)
    sum+=a[i++];

    while(j<l2)
    sum1+=b[j++];

    res+=max(sum1, sum);
    return res;
}
