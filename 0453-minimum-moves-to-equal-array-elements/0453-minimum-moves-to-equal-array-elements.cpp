class Solution {
public:
    int minMoves(vector<int>& nums) {

        // reverse the problem don't increase n-1 elements just decrease one ; 
        int min_val = *min_element(nums.begin(), nums.end());
        // calculate tje minimum number 
        int moves = 0;
        
        for(int num : nums) {
            moves += num - min_val;
            // calculating moves to bring all the elements to min one by one 
        }
        
        return moves;
    }
};