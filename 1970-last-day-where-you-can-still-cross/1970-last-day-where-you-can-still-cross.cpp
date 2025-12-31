class Solution {
public:
    bool bfs(vector<vector<int>>& grid, int row, int col) {
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int,int>> q;

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                visited[0][j] = true;
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == row - 1) return true;

            for (auto &d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 && nj >= 0 && ni < row && nj < col &&
                    !visited[ni][nj] && grid[ni][nj] == 0) {

                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int left = 1, right = cells.size(), ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            vector<vector<int>> grid(row, vector<int>(col, 0));

            for (int i = 0; i < mid; i++) {
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            if (bfs(grid, row, col)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
