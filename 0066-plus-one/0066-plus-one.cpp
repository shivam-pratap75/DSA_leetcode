class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits[n-1]!=9){
            digits[n-1]+=1;
        }else{
            bool temp=true;
            for(int i=n-1;i>=0;i--){
               
                if(digits[i]!=9){
                    digits[i]+=1;
                    temp=false;
                    break;
                }else{
                     digits[i]=0;
                }
                }
                if(temp){
                    digits.push_back(0);
                    digits[0]+=1;
                }


            }


        
        return digits;
        
    }
};