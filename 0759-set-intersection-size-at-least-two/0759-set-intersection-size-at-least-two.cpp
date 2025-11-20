class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // Sort by end point
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int result = 0;
        int pre1 = -1, pre2 = -1;

        for(const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            
            // Optimized: Direct checks without function call
            bool firstIn = (pre1 >= start && pre1 <= end);
            bool secondIn = (pre2 >= start && pre2 <= end);
            
            if(firstIn && secondIn) {
                continue;  // Both points cover the interval
            } 
            else if(secondIn) {
                // Only second point covers, add the largest possible
                if(pre2 == end) {
                    pre1 = end - 1;  // Ensure distinct points
                } else {
                    pre1 = pre2;
                    pre2 = end;
                }
                result++;
            } 
            else {
                // No points cover, add two largest points
                pre1 = end - 1;
                pre2 = end;
                result += 2;
            }
        }
        return result;      
    }
};