// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int v[], int n){
	    
	    int i=0,j=n-1;
	    int ans=-1;
	    while(i<=j)
	    {
	        int mid((i+j)/2);
	        
	        if((mid-1>=0&&v[mid]!=v[mid-1]||mid-1<0)&&(mid+1<n&&v[mid+1]!=v[mid])||mid+1>=n)
	        {
	            ans=v[mid];
	            break;
	        }
	        else if(mid-1>=0&&v[mid-1]==v[mid])
	        {
	            mid--;
	        }
            if((mid)%2)
            {
                j=mid-1;
            }
            else i=mid+2;
        
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}
  // } Driver Code Ends