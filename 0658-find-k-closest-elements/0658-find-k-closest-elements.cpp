class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<pair<int,int>> temp;

        for(int i = 0; i < arr.size(); i++){
            temp.push_back({abs(arr[i] - x), arr[i]});
        }

        sort(temp.begin(), temp.end());   

        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(temp[i].second);
        }

        sort(result.begin(), result.end());  
        return result;
    }
};