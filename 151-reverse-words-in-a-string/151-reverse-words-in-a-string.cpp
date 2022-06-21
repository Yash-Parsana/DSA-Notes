
class Solution {
public:
    string reverseWords(string s) {
  
        
        for(int z=0;z<s.size();z++)
        {
            int k=0;
            while(s[z]==' ')z++,k++;
            
            if(k>1)
            {
                s=s.substr(0,z-k+1)+s.substr(z);
                z=z-k;
            }
        }
        
        
        int i=0,j=s.size()-1;
        
        
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;j--;
        }
        
        i=0;j=0;
        
        for(int z=0;z<=s.size();z++)
        {
            if(z==s.size()||s[z]==' '){
            
            j=z-1;
            while(i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            i=z+1;
            }
        }
        
        i=0;j=0;
        
        while(s[i]==' ')i++;
        
        s=s.substr(i);
        
        i=s.size()-1;
        while(s[i]==' ')i--;
        
        s=s.substr(0,i+1);
        
        return s;
    }
};