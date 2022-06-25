class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int> row,col,box;
            for(int j=0;j<9;j++){
                if(row.count(board[i][j]) && board[i][j]!='.') return false;
                else row[board[i][j]]=0;
                if(col.count(board[j][i]) && board[j][i]!='.') return false;
                else col[board[j][i]]=0;
                if(box.count(board[3*(i/3)+j/3][3*(i%3)+j%3]) && board[3*(i/3)+j/3][3*(i%3)+j%3]!='.') return false;
                else box[board[3*(i/3)+j/3][3*(i%3)+j%3]]=0;
            }
        }
        return true;
    }
};