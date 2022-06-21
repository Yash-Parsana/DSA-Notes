// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& r, int n) 
    {
        int c=0;
        
        for(int z=1;z<n;z++)
        {
            if(r[c][z]) c=z;
        }
        
        for(int z=0;z<n;z++)
        {
            if(c!=z&&(r[c][z]||!r[z][c]))return -1;
        }
        return c;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends