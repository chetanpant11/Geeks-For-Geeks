#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,
                      string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		cin>>s[i];

		string tt;
		cin>>tt;


		vector<string> res = findMatchedWords(s,tt);
  sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
		cout<<endl;

	}
}// } Driver Code Ends


/* The function returns a  vector of strings
present in the dictionary which matches
the string pattern.
You are required to complete this method */
string en(string s)
{
    unordered_map<char,int> mp;
    int k=0;
    string chk="";
    for(int i=0;i<s.size();i++)
    {
        if(mp.find(s[i])==mp.end())
            mp[s[i]]=k++;

        chk+= char(mp[s[i]]);
    }
    return chk;

}
vector<string> findMatchedWords(vector<string> v,
                      string s)
{
    string chk=en(s);
    vector<string> ans;
    for(auto k:v)
    {
        if(s.size()==k.size()&&chk==en(k))
            ans.push_back(k);
    }
    return ans;

}
