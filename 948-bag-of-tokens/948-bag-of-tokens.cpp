class Solution {
public:
    int bagOfTokensScore(vector<int>& tk, int p) {
        if(tk.size()==0)return 0;
        sort(tk.begin(),tk.end());
        int n=tk.size();
        int i=0,j=n-1;
        int ans=0,sum=0;
        if(tk[0]>p)return 0;
        // vector<int> pre;
        for(int ii:tk){
            sum+=ii;
            // pre.push_back(sum);
        }
        if(sum<=p)return n;
        int score=0;
        while(i<=j)
        {
            if(p>=tk[i]){
                score++;
                p-=tk[i];
                i++;
                ans=max(ans,score);
            }
            else if(score>0)
            {
                score--;
                p+=tk[j];
                j--;
            }

        }
        return ans;
    }
};