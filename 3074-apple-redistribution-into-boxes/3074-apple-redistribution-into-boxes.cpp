class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        sort(capacity.begin(),capacity.end(),greater<int>());
        int result=0;
        int count=0;
        int sum=accumulate(apple.begin(),apple.end(),0);
        for(int i=0;i<capacity.size();i++){
            count+=capacity[i];
            if(count>=sum){
                result=i+1;
                break;
            }
        }
        return result;
    }
};