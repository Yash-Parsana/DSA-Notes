class Solution {
public:
    
//     vector<int> longestsequence(vector<int>&nums)
//     {
//         vector<int>seq,ans;
//         for(int i:nums)
//         {
//             auto it=lower_bound(seq.begin(),seq.end(),i);
//             ans.push_back(it-seq.begin());
//             if(it!=seq.end())*it=i;
//             else seq.push_back(i);
//         }
//         return ans;
//     }
    
//     int minimumMountainRemovals(vector<int>& nums) {
        
//         vector<int>is=longestsequence(nums);
//         reverse(nums.begin(),nums.end());
//         // for(int i:nums)cout<<i<<" ";
//         vector<int>ds=longestsequence(nums);

//         int len=INT_MAX;
//         for(int z=1;z<nums.size();z++)
//         {
//             len=min(len,(int)nums.size()-(is[z]+ds[z]+1));
//         }
        
//         return len;
//     }
        int minimumMountainRemovals(vector<int>& A) {
        int N = A.size(), ans = N;
        vector<int> a(N), b(N), v;
        for (int i = 0 ; i < N; ++i) {
            int x = A[i];
            auto it = lower_bound(begin(v), end(v), x);
            a[i] = it - begin(v);
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        v.clear();
        for (int i = N - 1; i >= 0; --i) {
            int x = A[i];
            auto it = lower_bound(begin(v), end(v), x) ;
            b[i] = it - begin(v); 
            if (it != end(v)) *it = x;
            else v.push_back(x);
        }
        for (int i = 1; i < N; ++i) {
            if (a[i] && b[i]) ans = min(ans, N - (a[i] + b[i] + 1));
        }
        return ans;
    }
};