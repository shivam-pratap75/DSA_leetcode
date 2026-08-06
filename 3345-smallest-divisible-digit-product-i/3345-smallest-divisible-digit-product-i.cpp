class Solution {
public:
    int smallestNumber(int n, int t) {

        if(n==100 )return n;

            int a=n%10;
            int b;
            if(n>=10){
            b=n/10;

            }else{
                b=1;
            }
            int x=n+t;
        
        while(n<=x){
            if((a*b)%t==0){
                return n;
            }
               n+=1;
                a+=1;
                a=a%10;
                 
            
        } 


                    return 0;
        
    }
};