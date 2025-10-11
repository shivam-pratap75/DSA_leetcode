class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int result = INT_MIN;
        
        
        for(int start = n - 1; start >= 0; start--) {
            
            if(start + k < n) {
                energy[start] += energy[start + k];
            }
            result = max(result, energy[start]);
        }
        
        return result;
    }
};