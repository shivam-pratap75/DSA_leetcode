class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;

        int i=0;
        int result=0;
        while(n){
            int a=n%2;
            if(a==0)result+=(1<<i);
            n=(n>>1);
            i++;
        }
        
       
        return result;
        
    }
};