class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(0);
        vc.push_back(w);

        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int mxh=0,mxv=0;
        
        for(int z=1;z<hc.size();z++)
        {
            mxh=max(mxh,hc[z]-hc[z-1]);
        }
        for(int z=1;z<vc.size();z++)
        {
            mxv=max(mxv,vc[z]-vc[z-1]);
        }
        int mod=1e9+7;

        return (1LL*mxh*mxv)%mod;
    }
};