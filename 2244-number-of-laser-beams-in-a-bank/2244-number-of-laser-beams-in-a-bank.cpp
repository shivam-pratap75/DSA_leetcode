class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
         
         int count_curr=0;
         int count_prev=0;
         int result=0;
        for(int i=0;i<bank.size();i++){
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){
                    count_curr++;
                }

                if(bank[i][j]=='1'){
                    result+=count_prev;
                }

            }
          
            if(count_curr!=0){
                  count_prev=count_curr;

            }
            count_curr=0;
        }
        return result;
        
    }
};