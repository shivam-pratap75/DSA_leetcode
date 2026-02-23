class Solution {
public:

    void solve(vector<int>& nums,int i,int j){

        while(i<=j){
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        
        k=k%n;
        solve(nums,0,n-1);
        solve(nums,0,k-1);
        solve(nums,k,n-1);
        
    }
};