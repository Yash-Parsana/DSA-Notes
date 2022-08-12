class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size(),m=matrix[0].size();

        vector<vector<int>>v(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')v[i][j]=1;
            }
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=0;y<m;y++)
            {
                if(v[z][y]!=0)
                {
                    v[z][y]+=v[z-1][y];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int j=0;
            stack<int>s;
            while(j<=m)
            {
                while(!s.empty()&&((j==m)||v[i][s.top()]>v[i][j]))
                {
                    int h=v[i][s.top()];
                    s.pop();
                    if(s.empty())ans=max(ans,h*(j));
                    else ans=max(ans,h*(j-s.top()-1));
                }
                s.push(j);
                j++;
            }
        }
        
        return ans;
    }
};