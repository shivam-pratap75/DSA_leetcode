class Solution {
public:
    int integerReplacement(int n) {

            int result=0;
            long long num=n;
        while(num>1){
            if(num & 1){
                if(num==3){
                    num--;
                }else if((num & 3)==3){
                    num++;
                }else{
                    num--;
                }


            }else{
                num=num>>1;
            }
            result++;
        }

    return result;
        
    }
};