class Solution {
public:
    int bestClosingTime(string customers) {
        int count_y=0,count_n=0;
        int result=0,total=INT_MAX;
        int n=customers.size();

        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                count_y++;
            }
        }
        if(count_y==n)return n;
        if(count_y==0)return 0;
         int result_check;
        for(int i=0;i<n;i++){
            int check;   
            if(customers[i]=='Y'){
                check=count_y+count_n;
                count_y--;
            }else{
                check=count_y+count_n;
                count_n++;
            }
            

            if(total>check){
                total=check;
                result=i;
                result_check=check;
            }

        }
        if(customers[n-1]=='Y'){
             int new_check=count_y+count_n;

             if(new_check<result_check){
                result=n;
             }

             
        }
        return result;
    }
};