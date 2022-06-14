// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
     bool possible(int v[],int mid,int s,int n)
    {
        int requireStudents = 1,cpage=0;
    
        for (int z = 0; z < n;z++)
        {
            if(v[z]>mid)
                return 0;
    
            if(cpage+v[z]<=mid)
            {
                cpage += v[z];
            }
            else{
                cpage = v[z];
                requireStudents++;
                if(requireStudents>s)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    
    int findPages(int v[], int n, int m)
    {
    
        int s = 0,e=0;
    
        for (int z = 0; z < n;z++){
            e += v[z];
        }
    
        int ans=-1;
        while(s<=e)
        {
            int mid = (s + e) / 2;
    
            if(possible(v,mid,m,n))
            {
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends