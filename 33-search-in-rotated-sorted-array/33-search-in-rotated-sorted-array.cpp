class Solution {
public:
    int find_in_r_arr(vector<int> &v,int x,int i,int j)
    {
        if(i>j)
            return -1;
        int mid = (i + j) / 2;

        if(v[mid]==x)
            return mid;
        if(v[i]<=v[mid])
        {
            if(x>=v[i]&&x<=v[mid])
                return find_in_r_arr(v, x, i, mid - 1);
            return find_in_r_arr(v, x, mid + 1, j);
        }
        if(x>=v[mid]&&x<=v[j])
            return find_in_r_arr(v, x, mid + 1, j);
        return find_in_r_arr(v, x, i, mid - 1);
    }

    int search(vector<int>& v, int x) {
         return find_in_r_arr(v, x, 0, v.size() - 1);
    }
};