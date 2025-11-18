class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
 bool result=true;
 int i=0;
       while(i<n){

        if(bits[i]==1){

              if(i<n && bits[i+1]==0 || bits[i+1]==1){

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