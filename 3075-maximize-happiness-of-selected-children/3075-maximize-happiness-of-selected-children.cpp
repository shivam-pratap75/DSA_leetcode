class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
       sort(happiness.begin(),happiness.end(),greater<int>());
        long long result=0;

       for(int i=0;i<k;i++){
        int check=happiness[i]-i;

        if(check>0){
            result=result + long(happiness[i]-i);
        }


       } 
       return result;
    }
};