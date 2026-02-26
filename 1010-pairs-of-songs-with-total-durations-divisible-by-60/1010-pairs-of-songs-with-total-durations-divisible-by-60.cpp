class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {

        unordered_map<int,int> temp;
        int n=time.size(),result=0;
        for(int i=0;i<n;i++){

            int a=time[i]%60;
            int check=(60-a)%60;
            if(temp.count(check)!=0){
                result+=temp[check];
            }

            temp[a]++;

        }
        return result;
        
    }
};