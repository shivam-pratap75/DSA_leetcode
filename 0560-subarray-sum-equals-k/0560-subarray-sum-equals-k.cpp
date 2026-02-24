class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        int n=nums.size();
        int result=0;
        int sum=0;

        temp.insert({0,1});
        for(int i=0;i<n;i++){
            sum+=nums[i];

            int x=sum-k;
            if(temp.find(x)!=temp.end()){
                result+=temp[x];
            }
            temp[sum]++;

            
        }

        
    return result;
        
    }
};