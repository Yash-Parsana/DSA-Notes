class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = {efficiency[i], speed[i]};
        sort(begin(v),end(v),greater<pair<int,int>>());
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto& [e, s]: v){
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
};