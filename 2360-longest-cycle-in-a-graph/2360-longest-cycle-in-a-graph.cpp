class Solution {
public:
int dfs(int i, int from, int dist, vector<int>& e, vector<pair<int, int>>& memo) {
    if (i != -1) {
        auto [dist_i, from_i] = memo[i];
        if (dist_i == -1) {
            memo[i] = {dist, from};
            return dfs(e[i], from, dist + 1, e, memo);
        }
        if (from_i == from)
            return dist - dist_i;
    }
    return -1;
}    
int longestCycle(vector<int>& e) {
    int res = -1;
    vector<pair<int, int>> memo(e.size(), {-1, -1});
    for (int i = 0; i < e.size(); ++i)
        res = max(res, dfs(i, i, 0, e, memo));
    return res;
}
};