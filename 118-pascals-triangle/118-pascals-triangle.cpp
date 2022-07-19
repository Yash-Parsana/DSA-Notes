class Solution {
public:
    vector<vector<int>> generate(int &n) {
        vector<vector<int>> v;
        if(n==0)return v;
        v.push_back({1});
        if(n==1)return v;
        
        v.push_back({1, 1});

        for (int z = 2; z < n;z++)
        {
            int i = 1;
            vector<int> temp;
            temp.push_back(1);
            while(i<z)
            {
                temp.push_back(v[z - 1][i - 1]+v[z-1][i]);
                i++;
            }
            temp.push_back(1);
            v.push_back(temp);
        }
        return v;
    }
};