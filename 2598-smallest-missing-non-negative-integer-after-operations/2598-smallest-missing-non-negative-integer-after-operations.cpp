class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        // if we have a series of no.s [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10...]
        // and divide be value 5, rem :[0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0....] they repeat

        // so for a nums like this: [0,1,2,3,4,5, 7] the MEX would be 6
        // becoz storing remainders like this: [0, 1, 3, 3, 4, 0,]
        //  we cnt the max cont nos. available:  1 2  3  4  5  6   ,  ans = 6 which is the min excl

        // the idea is that all nos. after infinite ops will lie in range [0, 1, 2, ... value -1]
        
        // so we build a freq map for all these value in 1st iteration on nums
        // and do 2nd iteration on maps to and keep decrementing freq once we've visited a num
        // the max value reached before freq==0 is the MEX 
        // eg: for val = 3 [0, 1, 2, 3, 4, 5, 6, 7, 10],  freq = [ (0: 3), (1: 4), (2:2) ]
        // so our iterations will work in a round robin fashion, mex = 0  (0:2) -> mex = 1 (1: 3) ->mex = 2 (2: 1)-> mex = 3 (mex%val =0) (0: 1)....... 2's freq will be 1st to turn 0, so the MEX would be 3+3+2 -> 8


        vector<int> mp(value);
        //building freq map
        for (auto& x : nums) {
            int v = (x % value + value) % value;
            mp[v]++;
        }
        int mex = 0;
        //iterating on map
        while (mp[mex % value] > 0) {
            mp[mex % value]--; // dec freq after vis
            mex++;
        }
        return mex;
    }
};
