class Solution {
public:
    int minFlips(int a, int b, int c) {
       


            int result=0;
        while (a > 0 || b > 0 || c > 0){

            int x=c &1;
            c=c>>1;
            int y=a&1;
            a=a>>1;
            int z=b&1;
            b=b>>1;

            if (x == 0) {
                if(y==1){
                    result+=1;
                }
                if(z==1)result+=1;
            } else {
                if (y == 0 && z == 0) {
                    result += 1;
                }
            }
            
        }

        return result;
    }
};