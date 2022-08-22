class Solution {
public:
    bool isPowerOfFour(int n) {
        
        while(n)
        {
            if(n%4)break;
            n/=4;
        }   
        // cout<<n<<endl;
        if(n!=1)return 0;
        return 1;
    }
};