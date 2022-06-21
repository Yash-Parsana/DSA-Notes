class Solution {
public:
    int myAtoi(string s) {
        int n=0;
    bool flag = 0,sign=0;
    for (int z = 0; z < s.size();z++)
    {
        if(!(s[z]>='0'&&s[z]<='9'))
        {
            if(flag)
            {
                if(sign)
                    return -n;
                else
                    return n;
                return n;
            }
            if(s[z]=='+'||s[z]=='-')
            {
                if(s[z]=='-')
                    sign = 1;
                flag = 1;
            }
            else if(s[z]!=' ')
            {
                // cout << "*";
                return n;
            }
        }

        else if(s[z]>='0'&&s[z]<='9')
        {
            flag=1;
            if(n>INT_MAX/10||n==INT_MAX/10&&((s[z]-'0')>INT_MAX%10))
            {
                return (sign ? INT_MIN : INT_MAX);
                
            }
            else
                n = n * 10 + (s[z] - '0');
        }
        
    }
    if(sign)
        n = -1 * abs(n);

    return n;
    }
};