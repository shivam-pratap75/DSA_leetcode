class Solution {
public:

int rev(int a){

    if(a<=9){
        return a;
    }
    int c=0;
    int res=0;
    while(a>0){
        c=a%10;
        res=res*10+c;
        a=a/10;
    }
    return res;

}
    int countNicePairs(vector<int>& nums) {
        int count =0;
        unordered_map<int,int>m2;
         const int MOD = 1e9 + 7;
        
        for(int i=0;i<nums.size();i++){
            int k=rev(nums[i]);
            k=nums[i]-k;
            if(m2.find(k)!=m2.end()){
                count=(count+m2[k])%MOD ;
                m2[k]++;
            }else{
                m2[k]++;
            }
               
        }
       
       return count % MOD;
    }
};