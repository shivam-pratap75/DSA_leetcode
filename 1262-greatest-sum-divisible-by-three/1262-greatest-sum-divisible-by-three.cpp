// class Solution {
// public:
//     int solve(vector<int>& nums, int i, int remainder, vector<vector<int>>& dp) {
//         if (i == nums.size()) {
//             return (remainder == 0) ? 0 : INT_MIN;
//         }
        
//         if (dp[i][remainder] != -1) {
//             return dp[i][remainder];
//         }
        
//         // Option 1: Don't take current element
//         int not_take = solve(nums, i + 1, remainder, dp);
        
//         // Option 2: Take current element
//         int take = nums[i] + solve(nums, i + 1, (remainder + nums[i]) % 3, dp);
        
//         return dp[i][remainder] = max(not_take, take);
//     }
    
//     int maxSumDivThree(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(3, -1));
//         return solve(nums, 0, 0, dp);
//     }
// };

// -----------------> solution with tracking with the help of vector<----------------------

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>q1,q2;
        int sum=0;
        for(int num:nums){
            sum+=num;
            if(num%3==1)q1.push_back(num);
            else if(num%3==2)q2.push_back(num);
        }
        sort(q1.begin(),q1.end());
        sort(q2.begin(),q2.end());

        if(sum%3==0)return sum;
        int ans=0;
        if(sum%3==1){
            int r1=q1.size()>0?q1[0]:INT_MAX;
            int r2=q2.size()>1?q2[0]+q2[1]:INT_MAX;
            ans=sum-min(r1,r2);
        }
        else{
            int r1=q2.size()>0?q2[0]:INT_MAX;
            int r2=q1.size()>1?q1[0]+q1[1]:INT_MAX;
            ans=sum-min(r1,r2);
        }
        return ans;
    }
};


//             -----------> solution with tracking two variables<----------------


// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         int sum = 0;

//         int min1_r1 = INT_MAX, min2_r1 = INT_MAX;
//         int min1_r2 = INT_MAX, min2_r2 = INT_MAX;

//         for (int x : nums) {
//             sum += x;
//             int r = x % 3;

//             if (r == 1) {
//                 if (x < min1_r1) {
//                     min2_r1 = min1_r1;
//                     min1_r1 = x;
//                 } else if (x < min2_r1) {
//                     min2_r1 = x;
//                 }
//             }
//             else if (r == 2) {
//                 if (x < min1_r2) {
//                     min2_r2 = min1_r2;
//                     min1_r2 = x;
//                 } else if (x < min2_r2) {
//                     min2_r2 = x;
//                 }
//             }
//         }

//         if (sum % 3 == 0) return sum;

//         if (sum % 3 == 1) {
//             int remove1 = min1_r1;
//             int remove2 = (min1_r2 != INT_MAX && min2_r2 != INT_MAX)
//                           ? min1_r2 + min2_r2
//                           : INT_MAX;
//             return sum - min(remove1, remove2);
//         } 
//         else { // sum % 3 == 2
//             int remove1 = min1_r2;
//             int remove2 = (min1_r1 != INT_MAX && min2_r1 != INT_MAX)
//                           ? min1_r1 + min2_r1
//                           : INT_MAX;
//             return sum - min(remove1, remove2);
//         }
//     }
// };