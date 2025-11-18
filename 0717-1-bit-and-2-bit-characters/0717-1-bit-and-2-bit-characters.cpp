class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
    if(n==1){ 
        return true;
    }
        if(bits[n-1]==0 && bits[n-2]==0){
            
                return true;
            
        }
 int val=0;
 bool result=true;
 int i=0;
       while(i<n){

        if(bits[i]==1){
              val=1;
              if(i<n && bits[i+1]==0 || bits[i+1]==1){
                val=0;
                result=false;
                i++;
              }
        }else{
            result=true;
        }
    i++;
       }
    return result;
      
    }
};