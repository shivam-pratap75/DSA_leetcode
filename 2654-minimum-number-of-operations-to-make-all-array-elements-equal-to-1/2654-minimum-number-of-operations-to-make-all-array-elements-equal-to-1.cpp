class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Count how many elements are already 1
        int onesCount = 0;
        for (int num : nums) {
            if (num == 1) onesCount++;
        }
        
        // If there's already at least one 1
        if (onesCount > 0) {
            return n - onesCount;
        }
        
        // Find shortest subarray with GCD = 1
        int minLen = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int currentGcd = nums[i];
            for (int j = i; j < n; j++) {
                currentGcd = gcd(currentGcd, nums[j]);
                if (currentGcd == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        
        // If no subarray with GCD = 1 exists
        if (minLen == INT_MAX) {
            return -1;
        }
        
        // Operations needed:
        // 1. (minLen - 1) operations to create a 1
        // 2. (n - 1) operations to spread the 1 to all elements
        return n + minLen - 2;
    }
};