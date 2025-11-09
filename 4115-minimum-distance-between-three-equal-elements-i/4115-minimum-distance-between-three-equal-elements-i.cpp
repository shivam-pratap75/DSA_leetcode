class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        unordered_map<int ,int> freq;
          unordered_map<int ,vector<int>> temp;
        int result=INT_MAX;
        for(int i=0;i<nums.size();i++){
            
            freq[nums[i]]++;
            temp[nums[i]].push_back(i);
        }

          for (const auto& pair : freq) {
         if(pair.second==3){
             int i=temp[pair.first][0];
             int j=temp[pair.first][1];
             int k=temp[pair.first][2];
             int final=abs(i-j) +abs(j-k)+abs(k-i);
             // int final=2*i*j;
             result=min(result,final);
             
         }
  if (pair.second > 3) {

    const vector<int>& reference = temp[pair.first];  
    int m = reference.size();

   
    for (int a = 0; a + 2 < m; a++) {

        int left  = reference[a];
        int right = reference[a + 2];

        int final = 2 * (right - left);

        result = min(result, final);
    }
}


              
    }
        if(result!=INT_MAX){
            return result;
        }else{
             return -1;
            
        }

       
        
    }
};