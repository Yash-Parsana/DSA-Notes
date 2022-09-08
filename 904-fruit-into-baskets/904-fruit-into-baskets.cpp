class Solution {
public:
    int totalFruit(vector<int>& f) {
        
        int pre1=0,pre2=0,temp=0,ans=0,pre1_c=0;
        // pre2 ,pre1 ,curr
        for(int curr:f)
        {
            if(pre1==curr||pre2==curr)
            {
                temp++;
                if(pre1==curr)pre1_c++;
                else {
                    pre1_c=1;
                    swap(pre1,pre2);
                }
            }
            else{
                pre2=pre1;
                pre1=curr;
                temp=pre1_c+1;
                pre1_c=1;
            }
            
            ans=max(ans,temp);
        }
        
        return ans;
    }
};