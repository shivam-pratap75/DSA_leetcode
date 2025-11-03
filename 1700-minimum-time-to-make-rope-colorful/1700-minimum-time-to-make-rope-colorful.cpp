class Solution {
public:
  int minCost(string colors, vector<int>& neededTime) {
    int totalTime = 0;
    int n = colors.size();
    
    for (int i = 0; i < n - 1; i++) {
        if (colors[i] == colors[i + 1]) {
            
            int currentMax = neededTime[i];
            totalTime += neededTime[i];
            
            
            while (i < n - 1 && colors[i] == colors[i + 1]) {
                totalTime += neededTime[i + 1];
                currentMax = max(currentMax, neededTime[i + 1]);
                i++;
            }
            
            
            totalTime -= currentMax;
        }
    }
    return totalTime;
}
};