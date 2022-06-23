class Solution {
public:
    
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>> a;
        for (auto &c: courses) {
            a.push_back(make_pair(c[1], c[0]));
        }
        sort(a.begin(), a.end());
        priority_queue<int> q;
        int end = 0;
        int result = 0;
        for (auto &c: a) {
            int d = c.second;
            if (c.first - d >= end) {
                q.push(d);
                end += d;
                result++;
            }
            else if (!q.empty()) {
                int x = q.top();
                if (x > d) {
                    q.pop();
                    q.push(d);
                    end -= x - d;
                }
            }
        }
        return result;
    }
};