class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:

        a=len(intervals)

        intervals.sort(key=lambda x:(x[0],-x[1]))
        result=a
        check=intervals[0][1]
        for i in range(1,len(intervals)):
            
            if intervals[i][1]<=check :
                result=result-1

            check=max(check,intervals[i][1])

        return result

        