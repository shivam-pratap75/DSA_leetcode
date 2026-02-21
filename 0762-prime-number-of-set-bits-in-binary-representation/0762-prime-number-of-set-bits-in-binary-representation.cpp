class Solution {
public:

    bool solve(int val){
        if(val==1)return false;
        
        for(int i=2;i*i<=val;i++){
            if(val % i==0){
                return false;
            }

        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {

        int result=0;
        for(int i=left;i<=right;i++){
            int val=__builtin_popcount(i);

            if(solve(val)){
                result++;
            }
        }
        return result;
        
    }
};