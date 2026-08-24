public class Solution {
    public int DeleteAndEarn(int[] nums) {

            int n=10001;

        int[] val=new int[n];

        foreach(int num in nums)val[num]+=num;

        int take=0;
        int skip=0;
        for(int i=0;i<n;i++){
            int takei= skip+val[i];
            int skipi=Math.Max(skip,take);

            take=takei;
            skip=skipi;
        }

        return Math.Max(take,skip);
    }
}