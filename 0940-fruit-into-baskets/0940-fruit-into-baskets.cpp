class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int left=0,right=0;
        int result=0;
          int key ;
        unordered_map<int,int> basket;
        unordered_map<int,int> val;

        for(int i=0;i<fruits.size();i++){
            basket[fruits[i]]++;
            val[fruits[i]]=i;
            right=i;

            if(basket.size()>2){
                 int value=INT_MAX-5;
                for(const auto& pair : val) {
             
              value =min(value,pair.second);
               if(pair.second == value) {
                  key = pair.first; 
                }
            
               }
               val.erase(key);
               basket.erase(key);
               left=value+1;
            }

            result=max(result,right-left+1);

        }




return result;
        
    }
};