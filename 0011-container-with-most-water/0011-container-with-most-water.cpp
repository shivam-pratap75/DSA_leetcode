class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1; 
        int result = 0;
        
        while (left < right) {
           
            int width = right - left;  
            int curr = width * min(height[left], height[right]);
            
            result = max(result, curr);
            
            
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;  
            }
        }
        
        return result;      
    }
};