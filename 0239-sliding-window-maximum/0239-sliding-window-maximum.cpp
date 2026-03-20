// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {


//         multiset<int> temp;
//         int left=0,right=0;
//         vector<int> result;
//         int n=nums.size();

//         while(right<n){
//             temp.insert(nums[right]);


//             if(temp.size()>k){
//                 auto a=temp.find(nums[left]);

//                 temp.erase(a);
//                 left++;
//             }

//             if(temp.size()==k){
//                 int b=*temp.rbegin();
//                result.push_back(b);

//             }
//             right++;

//         }
//         return result;
//     }
// };












class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> temp;
        vector<int> result;

        for(int i=0;i<nums.size();i++){


            
            if(!temp.empty() && temp.front()==i-k)temp.pop_front();

            while(!temp.empty() && nums[temp.back()]<nums[i]){
                temp.pop_back();
            }

            temp.push_back(i);

            if(i>=k-1){
                result.push_back(nums[temp.front()]);

            }
        }

        return result;
    }
};