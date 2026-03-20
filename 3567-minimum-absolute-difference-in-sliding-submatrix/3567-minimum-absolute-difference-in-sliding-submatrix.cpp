class Solution {
public:
    
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {

        vector<vector<int>> result;
        int n = grid.size();
        int m = grid[0].size();

        int i = 0;

        while(i <= n - k){

            int j = 0;
            vector<int> res;

            while(j <= m - k){

                vector<int> temp;

                for(int x = i; x < i + k; x++) {
                    for(int y = j; y < j + k; y++) {
                        temp.push_back(grid[x][y]);
                    }
                }

                sort(temp.begin(), temp.end());
                

                int mini = INT_MAX;

                if(temp.size() == 1) {
                    mini = 0;  
                } else {
                    for(int r = 1; r < temp.size(); r++){

        if(abs(temp[r]-temp[r-1])<mini && temp[r]!=temp[r-1]){
                mini=abs(temp[r]-temp[r-1]);
            }
                    }
                }

                if(mini==INT_MAX){
                    res.push_back(0);

                }else{
                res.push_back(mini);
                }
                j++;
            }

            result.push_back(res);
            i++;
        }

        return result;        
    }
};