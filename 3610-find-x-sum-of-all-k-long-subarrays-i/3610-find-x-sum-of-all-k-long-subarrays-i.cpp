class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
      
      vector<int> result;
      unordered_map<int,int> freq;
      int left=0;

      for(int i=0;i<nums.size();i++){
        freq[nums[i]]++;

        if(i-left+1>k){
            freq[nums[left]]--;
            if(freq[nums[left]]==0){
                freq.erase(nums[left]);
            }
            left++;

        }
        if(i-left+1==k){
            vector<pair<int,int>> temp(freq.begin(),freq.end());

            sort(temp.begin(),temp.end(),[](const pair<int,int>& a,const pair<int,int>& b){
                if(a.second ==b.second){
                    return a.first>b.first;
                }else{
                return a.second>b.second;
                }
            });
            int sum=0;
            int count=0;
            for(const auto &pair :temp){
                if(count<x){
                    sum+=pair.first*pair.second;
                }else{
                    break;
                }
                count++;
                
            }
            result.push_back(sum);
        }

       
      }
       
       
    return result;
          
        
    }
};