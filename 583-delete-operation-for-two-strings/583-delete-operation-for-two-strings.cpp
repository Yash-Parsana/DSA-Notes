
vector<vector<int>> dp(501,vector<int>(501));
class Solution {
public:
    
    int solve(string s1,string s2,int n,int m)
    {
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]= 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string s1, string s2) {
        
        
        int n=s2.size(),m=s1.size();
        int common=solve(s1,s2,n,m);

        return (n+m-2*common);
        
        
        
    }
};