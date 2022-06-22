class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        int i=0,j=0;
        
        while(i<v1.size()&&j<v2.size())
        {
            int vv1=0,vv2=0;
            bool b=0;
            while(i<v1.size()&&v1[i]!='.')
            {
                if(v1[i]!='0'||b)
                {
                    b=1;
                    vv1*=10;
                    vv1+=(v1[i]-'0');
                }
                i++;
            }
            
            b=0;
            while(j<v2.size()&&v2[j]!='.')
            {
                if(v2[j]!='0'||b)
                {
                    b=1;
                    vv2*=10;
                    vv2+=(v2[j]-'0');
                }
                j++;
            }
            
            if(vv1>vv2)return 1;
            else if(vv1<vv2)return -1;
            
            i++;j++;
        }
        
        if(i>=v1.size()&&j>=v2.size())return 0;
        
        while(i<v1.size())
        {
            int vv1=0;
            bool b=0;
            while(i<v1.size()&&v1[i]!='.')
            {
                if(v1[i]!='0'||b)
                {
                    b=1;
                    vv1*=10;
                    vv1+=(v1[i]-'0');
                }
                i++;
            }
            if(vv1>0)return 1;
            i++;
        }
        
        while(j<v2.size())
        {
            int vv2=0;
            bool b=0;
            while(j<v2.size()&&v2[j]!='.')
            {
                if(v2[j]!='0'||b)
                {
                    b=1;
                    vv2*=10;
                    vv2+=(v2[j]-'0');
                }
                j++;
            }
            if(vv2>0)return -1;
            j++;
        }
        return 0;
    }
};