class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend== INT_MIN && divisor== -1) return INT_MAX;
        
        unsigned long int divid=abs(dividend), divis=abs(divisor);
        unsigned int sum=0;
        
        for (int i = 31; i >= 0; i--){   
            if (divid >> i >= divis){
                sum += 1 << i, divid -= divis << i;
            }       
        }		
        return (dividend > 0) == (divisor > 0) ? sum : -sum;
    }
};