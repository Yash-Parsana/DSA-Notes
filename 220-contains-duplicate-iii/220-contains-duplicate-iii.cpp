class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        using LLI = long long int;
        int N = nums.size();
        
        map<LLI, set<int>> lookup;
        
        for(int i = 0; i < N; ++i) {
            lookup[nums[i]].insert(i);
        }
        
        for(int j = 0; j < N; ++j) {
            LLI Aj = nums[j];
            LLI lo = Aj - t;
            LLI hi = Aj + t;
            
            auto lob = lookup.lower_bound(lo);
            auto hib = lookup.upper_bound(hi);
            for(auto it = lob; it != hib; ++it) {
                auto &indices = it->second;
                const int loi = j - k;
                const int hii = j + k;
                
                auto loib = indices.lower_bound(loi);
                auto hiib = indices.upper_bound(hii);
                for(auto iit = loib; iit != hiib; ++iit) {
                    int i = *iit;
                    if(i != j && abs(i - j) <= k)
                        return true;
                }
            }
        }
        return false;
    }
};