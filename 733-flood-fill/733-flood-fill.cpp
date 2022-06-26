class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int c) {
    
        if(v[sr][sc]==c)return v;
        queue<pair<int,int>> q;
        
        q.push({sr,sc});
        int pc=v[sr][sc];
        v[sr][sc]=c;
        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();
            
            if(i-1>=0&&v[i-1][j]==pc)
            {
                v[i-1][j]=c;
                q.push({i-1,j});
            }
            if(i+1<v.size()&&v[i+1][j]==pc)
            {
                v[i+1][j]=c;
                q.push({i+1,j});
            }
            if(j-1>=0&&v[i][j-1]==pc)
            {
                v[i][j-1]=c;
                q.push({i,j-1});
            }
            if(j+1<v[0].size()&&v[i][j+1]==pc)
            {
                v[i][j+1]=c;
                q.push({i,j+1});
            }
            
        }
        return v;
    }
};