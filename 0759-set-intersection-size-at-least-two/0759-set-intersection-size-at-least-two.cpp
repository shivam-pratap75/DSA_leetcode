class Solution {
public:
    int is_check(int start, int end, int pre1, int pre2) {
        int count = 0;
        if(pre1 >= start && pre1 <= end) count++;
        if(pre2 >= start && pre2 <= end) count++;
        
        if(count >= 2) {
            return 0; 
        } else if(count == 1) {
            return 1;  
        } else {
            return 2;  
        }
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int result = 0;
        int pre1 = -1, pre2 = -1;

        for(int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            int val = is_check(start, end, pre1, pre2);

            if(val == 0) {
                continue;
            } else if(val == 1) {
                
                if(pre2 == end) {
                    pre1 = end - 1;  
                } else {
                    pre1 = pre2;
                    pre2 = end;
                }
                result++;
            } else {
                pre1 = end - 1;
                pre2 = end;
                result += 2;
            }
        }
        return result;      
    }
};