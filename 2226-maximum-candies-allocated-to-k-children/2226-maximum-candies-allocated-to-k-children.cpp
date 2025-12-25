class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        
        
        if (total < k) return 0;
        
        // Binary search for the maximum candies per child
        int left = 1;
        int right = *max_element(candies.begin(), candies.end());
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Count how many children can get 'mid' candies
            long long count = 0;
            for (int pile : candies) {
                count += pile / mid;  // Each pile can contribute pile/mid children
            }
            
            if (count >= k) {
                // We can give at least 'mid' candies to k children
                result = mid;
                left = mid + 1;  // Try for a larger number
            } else {
                // We can't give 'mid' candies to k children
                right = mid - 1;  // Try a smaller number
            }
        }
        
        return result;
    }
};