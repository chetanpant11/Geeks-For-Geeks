#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}// } Driver Code Ends
/*you are required to complete this method*/
int convertFive(int n) {
    int a=0;
    int q,c;
    while(n)
    {
        q=n%10;
        if(q==0)
        c=5;
        else
        c=q;
        a=a*10+c;
        n=n/10;
    }
    int aa=0;
    while(a)
    {
        q=a%10;
        aa=aa*10+q;
        a/=10;
    }
    return aa;
}



