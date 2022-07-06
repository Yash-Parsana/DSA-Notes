class Solution {
public:
//     void show(vector<int> v)
//     {
//         for(int i:v)cout<<i<<" ";
    
//         cout<<endl;
//     }
    int longestPalindromeSubseq(string s1) {
        int n=s1.size();
        string s2=s1;
        reverse(s2.begin(),s2.end());
        
        vector<int> dp(n,0);
        
        bool b=0;
        for(int z=0;z<n;z++)
        {
            if(s1[0]==s2[z])b=1;
            if(b)dp[z]=1;
        }
        // show(dp);
        vector<int> temp(n,0);
        for(int z=1;z<n;z++)
        {
            for(int y=0;y<n;y++)
            {
                if(y==0)
                {
                    // cout<<s1[z]<<" "<<s2[z]<<
                    if(s1[z]==s2[y])temp[y]=1;
                    else temp[y]=dp[y];
                }
                else{
                    if(s1[z]==s2[y])
                        temp[y]=dp[y-1]+1;
                    else
                        temp[y]=max({temp[y],dp[y],temp[y-1]});
                }
            }
            // show(dp);
            dp=temp;
        }
        return dp[n-1];
    }
};