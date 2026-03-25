class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        vector<long long> temp;

        
        for(int i=0;i<grid.size();i++){
            long long sum=0;
            for(int j=0;j<grid[0].size();j++){
                sum += grid[i][j];
            }
            temp.push_back(sum);
        }

        long long total = accumulate(temp.begin(), temp.end(), 0LL);

        if(total % 2 != 0) return false;


        long long num = 0;
        for(int i=0;i<temp.size();i++){
            num += temp[i];
            if(num == total/2) return true;
        }


        int m = grid.size(), n = grid[0].size();
        long long check = 0;

        for(int j = 0; j < n; j++){
            long long colSum = 0;
            for(int i = 0; i < m; i++){
                colSum += grid[i][j];
            }
            check += colSum;
            if(check == total/2) return true;
        }

        return false;
    }
};