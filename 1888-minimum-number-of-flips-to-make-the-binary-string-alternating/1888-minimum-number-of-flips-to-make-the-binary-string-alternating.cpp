class Solution {
public:

    int minFlips(string s) {

        int result=INT_MAX,n=s.length();   
    
            string temp=s+s;

     int odd=0,eve=0;
            int j=0;
            int left=0;
        while(j<2*n){
            if(j%2==0){

                if(temp[j]=='1'){
                    eve++;
                }else{
                    odd++;
                }
            }else{
                if(temp[j]=='1'){
                    odd++;
                }else{
                    eve++;
                }

            }

            if(j-left+1>n){
                  if(left%2==0){

                if(temp[left]=='1'){
                    eve--;
                }else{
                    odd--;
                }
            }else{
                if(temp[left]=='1'){
                    odd--;
                }else{
                    eve--;
                }

            }

                left++;
            }

             if(j - left + 1 == n) {
                result = min(result, min(odd, eve));
            }

            j++;


        }
        
    



       return result;
    }
};