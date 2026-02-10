class Solution {
public:
    int longestBalanced(vector<int>& nums) {

        
    int n=nums.size();
    int result=0;
        for(int i=0;i<n;i++){
        unordered_set<int> seve;
        unordered_set<int> sodd;

            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    seve.insert(nums[j]);
                }else{
                    sodd.insert(nums[j]);
                }

                if(seve.size()==sodd.size()){
                    result=max(result,j-i+1);
                }
            }
        }


        
        return result;
    }
};