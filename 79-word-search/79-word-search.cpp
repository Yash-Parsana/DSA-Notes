class Solution {
public:
   int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,-1,1};
    int n, m;
    bool DFS(vector<vector<char>>& board, int i, int j, vector<vector<int>> &visited, string &word, int idx)
    {
        if(idx == word.size()) return true;
        if(i >= n || i < 0 || j >= m || j < 0) return false;
        if(visited[i][j] == 1) return false;
        if(board[i][j] != word[idx]) return false;
        visited[i][j] = 1;
        int nxtx, nxty;
        for(int x = 0; x < 4; x++)
        {
            nxtx = i + dirx[x];
            nxty = j + diry[x];
            if(DFS(board, nxtx, nxty, visited, word, idx+1))
                return true;
        }
        visited[i][j] = 0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(DFS(board, i, j, visited, word, 0))
                    return true;
            }
        }
        return false;
    }
};