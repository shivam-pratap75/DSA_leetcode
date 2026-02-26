class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

            vector<int>temp(60,0);
        int n=time.size(),result=0;
        for(int i=0;i<n;i++){

            int a=time[i]%60;
            int check=(60-a)%60;
            if(temp[check]!=0){
                result+=temp[check];
            }

            temp[a]+=1;

        }
        return result;
        
    }
};