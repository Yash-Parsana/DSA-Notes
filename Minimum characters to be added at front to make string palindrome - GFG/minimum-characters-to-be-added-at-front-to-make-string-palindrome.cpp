// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    vector<int> prefixVector(string s)
    {
        vector<int> v(s.size(),0);
        
        for(int z=1;z<s.size();z++)
        {
            int t=v[z-1];
            
            while(t>0&&s[t]!=s[z]) t=v[t-1];
            
            if(s[z]==s[t])t++;
            
            v[z]=t;
            
        }
        return v;
    }

    int minChar(string s){
        
        string str=s;
        reverse(str.begin(),str.end());
        vector<int> v=prefixVector(s+"&"+str);
        
        return s.size()-v.back();
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends