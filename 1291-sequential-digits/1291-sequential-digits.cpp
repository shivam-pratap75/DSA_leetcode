class Solution {
public:
    void solve(int n,vector<int>& result,int& low,int& high,int start){

            if(n>=low && n<=high){
                result.push_back(n);

            }
            
        for(int i=start+1;i<=9;i++){
            n=n*10;
            n+=i;
            if(n>high)return;
            if(n>=low ){
                result.push_back(n);

            }


            
        }

    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

         for(int i=1;i<=9;i++){
                int num=i;
            solve(num,result,low, high,i);
         }
         sort(result.begin(),result.end());
         return result;
        
    }
};