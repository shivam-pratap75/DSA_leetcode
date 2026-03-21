class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        
        int n=nums.size();
        int left=0,right=0;

        set<int> temp;
        
        while(right<n){

            if(temp.size()>indexDiff){
                temp.erase(temp.find(nums[left]));
                left++;
            }

            auto it=temp.lower_bound(nums[right]-valueDiff);

            if(it!=temp.end() && *it<=nums[right]+valueDiff)return true;

            temp.insert(nums[right]);


            right++;
        }



        return false;
    }
};