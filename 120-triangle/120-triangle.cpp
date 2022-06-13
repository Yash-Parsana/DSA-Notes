class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++) 
			dp[n-1][i] = triangle[n-1][i];
        
        
		for(int i = n-2; i >= 0; i--) {
			for(int j = 0; j <=i ; j++) {
				int temp1 = triangle[i][j] + dp[i+1][j];
				int temp2 = triangle[i][j] + dp[i+1][j+1];
				dp[i][j] = min(temp1, temp2);
			}
		}
		
        return dp[0][0];
	}
};