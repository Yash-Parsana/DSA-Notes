class Solution {
public:
    string multiply(string num1, string num2) {
        if(num2.length()<num1.length()){
            swap(num1,num2);
        }
        vector<int> ans(num1.length()+num2.length(),0);
        if(num1=="0" || num2=="0") return "0";
        int carry=0,carry2=0;
        for(int i=num2.size()-1;i>=0;i--){
            for(int j=num1.size()-1;j>=0;j--){
                
                ans[i+j+1]+=(((num2[i]-'0')*(num1[j]-'0')+carry)%10+carry2);
                
                if(ans[i+j+1]>9){
                   
                    carry2=ans[i+j+1]/10;
                    ans[i+j+1]%=10;
                }
                else{
                    carry2=0;
                }
                if((num2[i]-'0')*(num1[j]-'0')+carry>9){
                    carry=((num2[i]-'0')*(num1[j]-'0')+carry)/10;
                }
                else{
                    carry=0;
                }
               
            }
            ans[i]=(carry+carry2);
            carry=0,carry2=0;
//             for(int i:ans){
//                 cout<<i;
//             }
//             cout<<endl;
             
           
        }
        int i=0;
        while(ans[i]==0){
            i++;
        }
        if(carry) {
            ans[i-1]=carry;
            i-=1;
        }
        carry=0;
       
        string answer="";
        for(int j=i;j<ans.size();j++){
            answer+=to_string(ans[j]);
        }
        return answer;
    }
};