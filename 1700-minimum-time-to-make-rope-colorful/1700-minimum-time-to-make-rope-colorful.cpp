class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.size();
        int currentMax = 0;
        
        for (int i = 0; i < n; i++) {
          
            if (i > 0 && colors[i] != colors[i - 1]) {
                currentMax = 0;
            }
            
            
            if (currentMax < neededTime[i]) {
                totalTime += currentMax;  
                currentMax = neededTime[i];  
            } else {
                totalTime += neededTime[i];  
            }
        }
        return totalTime;
    }
};