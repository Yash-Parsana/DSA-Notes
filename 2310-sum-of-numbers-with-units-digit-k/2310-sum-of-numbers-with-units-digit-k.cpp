class Solution {
public:
    int minimumNumbers(int num, int k) {
     
        if(num==0)return 0;
        for(int z=1;z<=10;z++)
        {
            if((k*z)%10==num%10&&z*k<=num) return z;
        }
        return -1;
    }
};