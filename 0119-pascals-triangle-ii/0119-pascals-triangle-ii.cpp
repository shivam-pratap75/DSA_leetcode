class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.push_back(1);

        for(int i=1;i<=rowIndex;i++){
            long long a= 1LL *result[i-1]*(rowIndex-i+1)/i;
            result.push_back((int)a);
        }
        return result;
    }
};