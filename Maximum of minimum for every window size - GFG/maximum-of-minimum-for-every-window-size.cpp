// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> ans(n,0);
        vector<int> temp(n,0);
        stack<int> s;
        
        for(int z=n-1;z>=0;z--)
        {
            while(!s.empty()&&arr[s.top()]>=arr[z]) s.pop();
            
            if(s.empty()) temp[z]=n-1;
            
            else temp[z]=s.top()-1;
            
            s.push(z);
        }
        
        s=stack<int>();
        for(int z=0;z<n;z++)
        {
            while(!s.empty()&&arr[s.top()]>=arr[z]) s.pop();
            
            if(s.empty()) temp[z]=temp[z]+1;
            
            else temp[z]=temp[z]-s.top();
            s.push(z);
        }
        
        for(int z=0;z<n;z++)
        {
            if(temp[z]!=0)
                ans[temp[z]-1]=max(ans[temp[z]-1],arr[z]);
            
            // cout<<temp[z]<<" "<<ans[temp[z]-1]<<endl;

        }
        for(int z=n-2;z>=0;z--)
        {
            ans[z]=max(ans[z],ans[z+1]);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends