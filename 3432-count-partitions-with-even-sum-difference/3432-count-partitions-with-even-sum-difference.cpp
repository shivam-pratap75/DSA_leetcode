class Solution {
public:
    int countPartitions(vector<int>& nums) 
    {
        int n = nums.size() , count = 0 ;

        for(int i = 0 ; i<n-1 ; i++)
        {
            int left = i , right = i+1;
            int leftsum = 0 , rightsum = 0 ; 
            for(int m = 0 ; m<=left  ;m++ ) leftsum +=nums[m];
            for(int p = right ; p<n ; p++) rightsum +=nums[p];

            if(abs(leftsum - rightsum)%2 == 0 )
            {
                count++;
            }
        }
        return count;
    }
};