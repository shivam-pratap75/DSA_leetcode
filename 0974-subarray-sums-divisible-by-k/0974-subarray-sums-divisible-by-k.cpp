class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> temp;
        int n=nums.size();
        int result=0;
        int sum=0;
        temp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)rem+=k;
            if(temp.find(rem)!=temp.end()){
                result+=temp[rem];
            }
            temp[rem]++;
        }

       
        return result;
    }
};