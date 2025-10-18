class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
//  long long n=0;
    long long left=LONG_MIN;
    
    long long result=0;

// unordered_map<int,int>map;
for(int i=0;i<nums.size();i++){
    long long low=nums[i]-k;
    long long high=nums[i]+k;
    long long select=max(low,left+1);
    if(select<=high){
        result++;
        left=select;
    }
    // if(nums[i]<left){
    //     left=nums[i];
    // }
    // if(map[nums[i]]<=2*k){
    //  map[nums[i]]++;
    //  n++;   
    // }
}
   
//    for(const auto& pair : map) {
//     int key = pair.first;
//     int value=pair.second;
   
return result;

// }
//    result=(k-left)+(k+right)+1;


    // if(n<result){
    //     return n;
    // }else{
    //     return result;
    // }
        
        
    }
};