class Solution {
public:
    vector<int> reverseNumbers(vector<int>& nums) {
        vector<int> reversed;
        for(int num : nums) {
            int rev = 0;
            int n = num;
            while(n > 0) {
                rev = rev * 10 + n % 10;
                n /= 10;
            }
            reversed.push_back(rev);
        }
        return reversed;
    }

    int countDistinctIntegers(vector<int>& nums) {
        vector<int> reversed = reverseNumbers(nums);
        unordered_set<int> s(nums.begin(), nums.end()); 
        
        for(int num : reversed) {
            s.insert(num);
        }
        
        return s.size();
    }
};