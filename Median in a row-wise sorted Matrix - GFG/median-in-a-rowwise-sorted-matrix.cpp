// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &a, int r, int c){
        
        int mi=INT_MAX,mx=INT_MIN;
        for(int z=0;z<r;z++)
        {
            mi=min(mi,a[z][0]);
            mx=max(mx,a[z][c-1]);
        }
        
        int mid,ne=0,ae=(r*c+1)/2;
        while(mi<mx)
        {
            ne=0;
            mid=mi+(mx-mi)/2;
            for(int z=0;z<r;++z)
            {
                ne+=upper_bound(a[z].begin(),a[z].end(),mid)-a[z].begin();
            }
            // if(ne==ae)
            // {
            //     return mid;
            // }
            if(ne<ae)
            {
                mi=mid+1;
            }
            else
            {
                mx=mid;
            }
        }
        
        return mi;
       
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends