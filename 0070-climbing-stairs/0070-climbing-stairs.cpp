class Solution {
public:
  
    int climbStairs(int n) {
    
       int pre,pre_pre;
       if(n==1)return 1;
       pre=2;
       pre_pre=1;
       for(int i=3;i<=n;i++){
        
        int num=pre+pre_pre;
        pre_pre=pre;
        pre=num;

        
       }
    return pre;
        
    }
};