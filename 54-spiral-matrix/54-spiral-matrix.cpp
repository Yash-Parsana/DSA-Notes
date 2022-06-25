class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int u = -1, d = matrix.size(), r = matrix[0].size(), l = -1;
        int i = 0 , j = 0; 
        vector<int> sp_path;
        while (j < r){
            // go_right();
            while(j < r){
                sp_path.push_back(matrix[i][j]);
                ++j;
            }
            --j; ++i; ++u;
            // go_down();
            if(i >= d) break;
            while(i < d){
                sp_path.push_back(matrix[i][j]);
                ++i;
            }
             --i; --j; --r;
            // go_left();
            if(j <= l) break;
            while(j > l){
                sp_path.push_back(matrix[i][j]);
                --j;
            }
             ++j; --i; --d;
            // go_up();
            if(i <= u) break;
            while(i > u){
                sp_path.push_back(matrix[i][j]);
                --i;
            }
            ++i; ++j; ++l;
        }
        return sp_path;
    }
};