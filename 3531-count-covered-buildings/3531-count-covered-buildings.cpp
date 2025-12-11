class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minCol(n + 1 , n + 1);
        vector<int> maxCol(n + 1 , 0);
        vector<int> minRow(n + 1 , n + 1);
        vector<int> maxRow(n + 1 , 0);

        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            if (y < minCol[x]) minCol[x] = y;
            if (y > maxCol[x]) maxCol[x] = y;

            if (x < minRow[y]) minRow[y] = x;
            if (x > maxRow[y]) maxRow[y] = x; 
        }

        int cnt = 0;
        for (auto& b : buildings) {
            int x = b[0];
            int y = b[1];

            bool left = (y > minCol[x]);
            bool right = (y < maxCol[x]);
            bool up = (x > minRow[y]);
            bool down = (x < maxRow[y]);

            if (left && right && up && down) cnt++;
        }
        return cnt;
    }
};