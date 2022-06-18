class Solution {
public:
int orangesRotting(vector<vector<int>>& v) {
        
        queue<pair<int,int>> q;
        
        int n=v.size(),m=v[0].size();
        
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<m;y++)
            {
                if(v[z][y]==2) q.push({z,y});
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int nn=q.size();
            ans++;
            bool b=0;
            while(nn--)
            {
                
                int i=q.front().first,j=q.front().second;
                q.pop();

                if(i-1>=0&&v[i-1][j]==1)
                {
                    b=1;
                    q.push({i-1,j}); 
                    v[i-1][j]=2;
                }
                if(i+1<n&&v[i+1][j]==1)
                {
                    b=1;
                    v[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j-1>=0&&v[i][j-1]==1)
                {
                    b=1;
                    v[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j+1<m&&v[i][j+1]==1)
                {
                    b=1;
                    v[i][j+1]=2;
                    q.push({i,j+1});  
                } 
                
            }
            if(!b)ans--;
            
        }
        
        for(auto i: v)
        {
            for(int j:i)
            {
                if(j==1) return -1;
            }
        }
        
        return ans;
        
    }
};