class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        vector<int> result;
        while(left<right){
            
            if( numbers[left]+numbers[right]<target){
               left++;

        }else if(target< numbers[left]+numbers[right]){
            right--;
        }else{
            result.push_back(left+1);
            result.push_back(right+1);
            break;
        }
        }
return result;

    }
};