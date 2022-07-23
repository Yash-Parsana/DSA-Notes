
class Solution {
public:
    
    void merge(vector<pair<int,int>> &v,int s,int e,int mid,vector<int>&ans)
    {
        vector<pair<int,int>> temp(e-s+1);
        
        int i=mid,j=e;
        int tt=e-s;
        while(i>=s&&j>=mid+1)
        {
            if(v[i].first<=v[j].first)
            {
                temp[tt]=v[j];
                j--;
            }
            else
            {
                ans[v[i].second]+=j-mid;
                temp[tt]=v[i];
                i--;
            }
            tt--;
        }
        
        while(i>=s)
        {
            temp[tt]=v[i];
            tt--;i--;
        }
        while(j>=mid+1)
        {
            temp[tt]=v[j];
            tt--;j--;
        }
        
        for(int z=e;z>=s;z--)
        {
            v[z]=temp.back();
            temp.pop_back();
        }
        
    }
    
    void mergeSort(vector<pair<int,int>>&v,int i,int j,vector<int>&ans)
    {
        if(i<j)
        {
            int mid=(i+j)/2;
            mergeSort(v,i,mid,ans);
            mergeSort(v,mid+1,j,ans);
            merge(v,i,j,mid,ans);
        }
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        
        vector<pair<int,int>> v(n);
        for(int z=0;z<n;z++)
        {
            v[z].first=nums[z];
            v[z].second=z;
        }
        
        vector<int>ans(n,0);
        
        mergeSort(v,0,n-1,ans);
        
        return ans;
        
    }
};