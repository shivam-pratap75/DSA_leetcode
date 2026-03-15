class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        int pre_start = intervals[0][0];
        int pre_end   = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            if(intervals[i][0] > pre_end) {

                result.push_back({pre_start, pre_end});

                pre_start = intervals[i][0];
                pre_end = intervals[i][1];

            } 
            else {

                pre_end = max(pre_end, intervals[i][1]);

            }
        }

        result.push_back({pre_start, pre_end});

        return result;
    }
};