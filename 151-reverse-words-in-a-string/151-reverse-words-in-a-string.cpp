
class Solution {
public:
string reverseWords(string str) {
        str.append(1,' ');
    int i,n=str.length();
    int low=0;
    int high;
    for(i=0;i<n;)
    {
        while(str[i]==' ' and i<n)
        i++;
        if(i>=n)
            break;
        low=i;
        high=i;
        while(str[high]!=' ' and high<n)
        high++;
        int t=high;
        high--;
        while(low<high)
        {
            swap(str[low],str[high]);
            low++;
            high--;
        }
        i=t;
    }
    reverse(str.begin(),str.end());
    int start=0;
    for(i=0;i<n;)
    {
        while(str[i]==' ' and i<n)
        i++;
        if(i>=n)
            break;
        int id=i;
        while(str[id]!=' ' and id<n)
        {
            str[start]=str[id];
            start++;
            id++;
        }
        str[start]=' ';
        start++;
        i=id;
    }
    return str.substr(0,start-1);
    }
};