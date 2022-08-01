class Solution {
public:
    bool checkOnesSegment(string s) {

        int fo=-1,so=-1,fz=-1,sz=-1;

        for(int z=0;z<s.size();z++)
        {
            if(s[z]=='0')
            {
                if(fz==-1)fz=z;
                sz=z;
            }
            else{
                if(fo=='1')fo=z;
                so=z;
            }
        }
        
        if(fz==-1||so<fz||sz<fo)return 1;
        return 0;
    }
};