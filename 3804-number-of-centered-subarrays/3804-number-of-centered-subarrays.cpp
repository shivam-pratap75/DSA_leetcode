class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            long long sum=0;
            unordered_map<long long,int>temp;
            for(int j=i;j>=0;j--){
                sum+=nums[j];
                temp[nums[j]]++;

                if(temp.count(sum)){
                    ans++;
                }

            }
        }
        return ans;
    }
};
