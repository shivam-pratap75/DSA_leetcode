class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        int mxlen=1;
        int used=0;
        int left=0;
        for(int right=0;right<n;right++){
            while((used &nums[right])!=0){
                used^=nums[left];
                left++;
            }
            used|=nums[right];
            mxlen=max(mxlen,right-left+1);
        }
    return mxlen;
    }
};