class Solution {
public:
    int robotSim(vector<int>& cm, vector<vector<int>>& obs)     {
             
        map<pair<int,int>,bool> m;
        
        for(auto i:obs)
        {
            m[{i[0],i[1]}]=1;
        }
        
        int dir=0; //0 north 1 east 2 south 3 west
        int x=0,y=0,ans=0;
        for(int i:cm)
        {
            if(i==-1)
            {
                dir++;
                if(dir>3)dir=0;
            }
            else if(i==-2)
            {
                dir--;
                if(dir<0)dir=3;
            }
            else{

                for(int j=0;j<i;j++)
                {
                    if(dir==0)
                    {
                        y++;
                        if(m.find({x,y})!=m.end())
                        {
                            y--;
                            break;
                        }                            
                    }
                    else if(dir==1)
                    {
                        x++;
                        if(m.find({x,y})!=m.end())
                        {
                            x--;
                            break;
                        }                            
                    }
                    else if(dir==2)
                    {
                        y--;
                        if(m.find({x,y})!=m.end())
                        {
                            y++;
                            break;
                        }                            
                    }
                    else if(dir==3)
                    {
                        x--;
                        if(m.find({x,y})!=m.end())
                        {
                            x++;
                            break;
                        }                            
                    }
                    
                    ans=max(ans,(x*x+y*y));
                    
                }
            
            }
        }
        
        return ans;
    }
};